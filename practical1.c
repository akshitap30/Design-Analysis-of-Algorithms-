#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;time.h&gt;
void generate(int arr[], int n, int min, int max) {
for (int i = 0; i &lt; n; i++) {
arr[i] = rand() % (max - min + 1) + min;
}
}
void naiveFindMinMax(int arr[], int n, int *minIndex, int *maxIndex) {
*minIndex = -1;
*maxIndex = -1;
for (int i = 0; i &lt; n; i++) {
int isMin = 1;
int isMax = 1;
for (int j = 0; j &lt; n; j++) {
if (i != j) {
if (arr[i] &gt; arr[j])
isMin = 0;
if (arr[i] &lt; arr[j])
isMax = 0;
}
}
if (isMin &amp;&amp; *minIndex == -1)
*minIndex = i;
if (isMax &amp;&amp; *maxIndex == -1)
*maxIndex = i;
}
}
int compare(void *a, void *b) {
int x = *(int*)a;
int y = *(int*)b;
if (x &lt; y) {
return -1;
} else if (x &gt; y) {
return 1;
} else {
return 0;
}
}
//binary search

int binarySearch(int arr[], int n) {
int left = 0, right = n - 1;
int result = -1;
while (left &lt;= right) {
int mid = left + (right - left) / 2;
if (arr[mid] &gt;= 30) {
result = mid;
right = mid - 1;
} else {
left = mid + 1;
}
}
return result;
}

int linearSearch(int arr[], int n) {
for (int i = 0; i &lt; n; i++) {
if (arr[i] &gt;= 30) {
return i;
}
}
return -1;
}
int main() {
srand(time(0));
int n;
n = 1000000;
int minIndex,maxIndex;
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL) {
printf(&quot;Memory allocation failed!\n&quot;);
return 1;
}
generate(arr, n, 20, 50);
double duration;
clock_t start, end;
start = clock();
// int minVal = findMin(arr, n);
end = clock();

duration = (((double)(end - start)) / CLOCKS_PER_SEC);
qsort(arr, n, sizeof(int), compare);

printf(&quot;First occurance found at %d through binary search\n&quot;,binarySearch(arr,n));
printf(&quot;First occurance found at %d through linear search\n&quot;,linearSearch(arr,n));

printf(&quot;For the input size = %d, Time required to find minimum value in a list = %lf seconds\n&quot;,
n, duration);
//rintf(&quot;The minimum value found is: %d\n&quot;, minVal);
//rintf(naiveFindMinMax(arr,n,&amp;minIndex,&amp;maxIndex));
// naiveFindMinMax(arr,n,&amp;minIndex,&amp;maxIndex);
// Warning: This will be very slow for large n!
naiveFindMinMax(arr, n, &amp;minIndex, &amp;maxIndex);
printf(&quot;Naive min index: %d, value: %d\n&quot;, minIndex, arr[minIndex]);
printf(&quot;Naive max index: %d, value: %d\n&quot;, maxIndex, arr[maxIndex]);
free(arr);
arr = NULL;
// qsort(arr,n,compare);

return 0;
}
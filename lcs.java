public class lcs{
    
    public static void main(String[] args) {
        String x="AGCCCTAAGGGCTACCTAGCTT";
        String y="GACAGCCTACAAGCGTTAGCTTG";
    
        int m=x.length();
        int n=y.length();
        int[][] c=new int[m+1][n+1];
        char[][] b=new char[m+1][n+1];
        for(int i=1; i<=m; i++){
            for(int j=1;j<=n;j++){
                if(x.charAt(i-1)==y.charAt(j-1)){
                    c[i][j]=c[i-1][j-1]+1;
                    b[i][j]='d';
                }
                else if(c[i-1][j]>=c[i][j-1]) {
                    c[i][j]=c[i-1][j];
                    b[i][j]='u';
                } 
                else {
                    c[i][j]=c[i][j-1];
                    b[i][j]='s';
                }
            }
        }
    

        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0){
                    System.out.print("0 ");
                }
                else {
                    System.out.print(c[i][j]+""+b[i][j]+"  ");

                }
            }
            System.out.println();
        }
       
System.out.print("LCS IS:");
printlcs(b,x,m,n);
System.out.println();
System.out.println("Cost is :"+c[m][n]);

    
        }

    public static void printlcs(char b[][], String X, int i, int j){
        if(i==0||j==0){
            return;
        }
        else {
            if(b[i][j]=='d'){
            printlcs(b, X, i-1, j-1);
            System.out.print(X.charAt(i - 1));}
            else if(b[i][j]=='u') {
            printlcs(b, X, i-1, j);}
            else {
                printlcs(b, X, i, j-1);
            }
        }
    }
        
        }

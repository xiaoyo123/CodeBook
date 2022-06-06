#define N
#define MOD

struct matrix{
    int mat[N][N];
    matrix(){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++)
                mat[i][j] = 0;
        }
    }
    friend matrix operator * (matrix a, matrix b){
        matrix ret = matrix();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                for(int k = 0; k < N; k++)
                    ret.mat[i][j] += ((a.mat[i][k] * b.mat[k][j]) % MOD);
            }
        }
        return ret;
    } 
};
matrix Pow(matrix m, int n){
    n--;
    matrix ans = m;
    while(n){
        if(n & 1) ans = ans * m;
        m = m * m;
        n >>= 1;
    }
    return ans;
}
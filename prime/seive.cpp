#define MXN

bool IsPrime[MXN];

void init(){
    for(int i = 2; i < MXN; i++) IsPrime[i] = 1;
    IsPrime[0] = IsPrime[1] = 0;
}
void Make(){
    for(int i = 2; i < MXN; i++){
        if(IsPrime[i]){
            for(int j = 2; i * j <= MXN; j++)
                IsPrime[i * j] = 0;
        }
    }
}
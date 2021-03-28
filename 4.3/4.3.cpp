int main(){
    int a;
    int *a;
    int **a;
    int a[10];
    {
        int *a[10];
        sizeof a;
        auto b = *a[2];
    }
    {
        int (*a)[10];
        sizeof a;
        auto b = (*a)[2];
    }
}
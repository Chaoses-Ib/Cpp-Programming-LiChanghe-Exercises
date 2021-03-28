//const int *p 的类型是 只读整数的指针，int * const p 是 整数的只读指针。const int *p 可以更改指向的对象，但不能修改它的值；int * const p 可以修改指向对象的值，但不能更改指向的是谁。

int main(){
    int a = 248, b = 4;
    int const c = 21;
    int const *d = &a;
    int *const e = &b;
    int const * const f = &a;
    *c = 32;  //wrong，改正：删除
    *d = 43;  //wrong，改正：删除
    d = &b;
    e = &a;  //wrong，改正：删除
    *e = 34;
    *f = 25;  //wrong，改正：删除
    f = &a;  //wrong，改正：删除
}
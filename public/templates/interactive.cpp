int ask(int a,int b){
    cout << "? " << a << " " << b << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
void tell(int x){
    cout << "! " << x  << endl;
    cout.flush();
}
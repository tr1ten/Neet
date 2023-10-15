const long double eps = 1e-7;

int main(int argc, char const *argv[])
{
    double l = 0.0f, r=1e4f;

    double ans = -1;
    int ic = 10000;
    for (int i = 0; i < ic && l + eps < r; ++i)
    {
        float mid = 0.5f * (l + r);
        if (ok(mid)){
            r = mid;
            ans = mid;}
        else
            l = mid;
    }
    return 0;
}

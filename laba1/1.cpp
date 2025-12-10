#include <windows.h>
#include <iostream>
#include <set>
using namespace std;

/* ======== 1 ======== */
class Pair1 {
    double first;
    int second;
public:
    bool init(double a, int b) {
        first=a; second=b;
        return true;
    }
    bool read() {
        if(!(cin>>first>>second)){
            cout<<"Ошибка ввода Pair1\n";
            return false;
        }
        return true;
    }
    void display() const {
        cout<<"Pair1: "<<first<<", "<<second<<"\n";
    }
    double power() const { return pow(first, second); }
};
Pair1 make_pair1(double a,int b) { Pair1 p; p.init(a,b); return p; }

/* ======== 2 ======== */
class Pair2 {
    double first, second;
public:
    bool init(double a,double b) { first=a; second=b; return true; }
    bool read() { if(!(cin>>first>>second)) { cout<<"Ошибка ввода Pair2\n"; return false;} return true; }
    void display()const { cout<<"Pair2: "<<first<<", "<<second<<"\n"; }
    double power()const { return pow(first,second); }
};
Pair2 make_pair2(double a,double b) { Pair2 p; p.init(a,b); return p; }

/* ======== 3 ======== */
class Pair3 {
    long long first,second;
public:
    bool init(long long a,long long b) {
        if(b==0) { cout<<"Ошибка: знаменатель=0 в Pair3\n"; return false; }
        first=a; second=b; return true;
    }
    bool read() {
        if(!(cin>>first>>second)) { cout<<"Ошибка ввода Pair3\n"; return false; }
        if(second==0) { cout<<"Ошибка: знаменатель=0 в Pair3\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair3: "<<first<<"/"<<second<<"\n"; }
    long long ipart()const { return first/second; }
};
Pair3 make_pair3(long long a,long long b) { Pair3 p; p.init(a,b); return p; }

/* ======== 4 ======== */
class Pair4 {
    int denom,count;
public:
    bool init(int d,int c) {
        static set<int> ok={1,2,5,10,50,100,500,1000,5000};
        if(!ok.count(d) || c<0) {
            cout<<"Ошибка: некорректный номинал/количество в Pair4\n";
            return false;
        }
        denom=d; count=c; return true;
    }
    bool read() {
        if(!(cin>>denom>>count)) { cout<<"Ошибка ввода Pair4\n"; return false;}
        return init(denom,count);
    }
    void display()const { cout<<"Pair4: "<<denom<<" x "<<count<<"\n"; }
    long long summa()const { return 1LL*denom*count; }
};
Pair4 make_pair4(int a,int b) { Pair4 p; p.init(a,b); return p; }

/* ======== 5 ======== */
class Pair5 {
    double price;
    int qty;
public:
    bool init(double p,int q) {
        if(p<0||q<0) { cout<<"Ошибка: отрицательные значения Pair5\n"; return false;}
        price=p; qty=q; return true;
    }
    bool read() {
        if(!(cin>>price>>qty)) { cout<<"Ошибка ввода Pair5\n"; return false;}
        if(price<0||qty<0) { cout<<"Ошибка: отрицательные значения Pair5\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair5: "<<price<<" * "<<qty<<"\n"; }
    double cost()const { return price*qty; }
};
Pair5 make_pair5(double a,int b) { Pair5 p; p.init(a,b); return p; }

/* ======== 6 ======== */
class Pair6 {
    int cal100;
    double kg;
public:
    bool init(int c,double k) {
        if(c<0||k<0) { cout<<"Ошибка: отрицательные значения Pair6\n"; return false;}
        cal100=c; kg=k; return true;
    }
    bool read() {
        if(!(cin>>cal100>>kg)) { cout<<"Ошибка ввода Pair6\n"; return false;}
        if(cal100<0||kg<0) { cout<<"Ошибка: отрицательные значения Pair6\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair6: "<<cal100<<" cal/100g, "<<kg<<" kg\n"; }
    double power()const { return cal100*(kg*1000/100); }
};
Pair6 make_pair6(int a,double b) { Pair6 p; p.init(a,b); return p; }

/* ======== 7 ======== */
class Pair7 {
    double L,R;
public:
    bool init(double a,double b) {
        if(a>b) { cout<<"Ошибка: L>R Pair7\n"; return false;}
        L=a; R=b; return true;
    }
    bool read() {
        if(!(cin>>L>>R)) { cout<<"Ошибка ввода Pair7\n"; return false;}
        if(L>R) { cout<<"Ошибка: L>R Pair7\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair7: ["<<L<<","<<R<<"]\n"; }
    bool rangecheck(double x)const { return x>=L && x<=R; }
};
Pair7 make_pair7(double a,double b) { Pair7 p; p.init(a,b); return p; }

/* ======== 8 ======== */
class Pair8 {
    int L,R;
public:
    bool init(int a,int b) {
        if(a>b) { cout<<"Ошибка: L>R Pair8\n"; return false;}
        L=a; R=b; return true;
    }
    bool read() {
        if(!(cin>>L>>R)) { cout<<"Ошибка ввода Pair8\n"; return false;}
        if(L>R) { cout<<"Ошибка: L>R Pair8\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair8: ["<<L<<","<<R<<")\n"; }
    bool rangecheck(int x)const { return x>=L && x<R; }
};
Pair8 make_pair8(int a,int b) { Pair8 p; p.init(a,b); return p; }

/* ======== 9 ======== */
class Pair9 {
    int h,m;
public:
    bool init(int a,int b) {
        if(a<0||b<0) { cout<<"Ошибка: отрицательное время Pair9\n"; return false;}
        h=a; m=b; return true;
    }
    bool read() {
        if(!(cin>>h>>m)) { cout<<"Ошибка ввода Pair9\n"; return false;}
        if(h<0||m<0) { cout<<"Ошибка: отрицательное время Pair9\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair9: "<<h<<"h "<<m<<"m\n"; }
    int minutes()const { return h*60+m; }
};
Pair9 make_pair9(int a,int b) { Pair9 p; p.init(a,b); return p; }

/* ======== 10 ======== */
class Pair10 {
    double A,B;
public:
    bool init(double a,double b) { A=a; B=b; return true; }
    bool read() { if(!(cin>>A>>B)) { cout<<"Ошибка ввода Pair10\n"; return false;} return true; }
    void display()const { cout<<"Pair10: "<<A<<"*x + "<<B<<"\n"; }
    double function(double x)const { return A*x+B; }
};
Pair10 make_pair10(double a,double b) { Pair10 p; p.init(a,b); return p; }

/* ======== 11 ======== */
class Pair11 {
    double A,B;
public:
    bool init(double a,double b) {
        if(a==0) { cout<<"Ошибка: A=0 Pair11\n"; return false;}
        A=a; B=b; return true;
    }
    bool read() {
        if(!(cin>>A>>B)) { cout<<"Ошибка ввода Pair11\n"; return false;}
        if(A==0) { cout<<"Ошибка: A=0 Pair11\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair11: "<<A<<"*x + "<<B<<"\n"; }
    double root()const { return -B/A; }
};
Pair11 make_pair11(double a,double b) { Pair11 p; p.init(a,b); return p; }

/* ======== 12 ======== */
class Pair12 {
    double x,y;
public:
    bool init(double a,double b) { x=a; y=b; return true;}
    bool read() { if(!(cin>>x>>y)) { cout<<"Ошибка ввода Pair12\n"; return false;} return true;}
    void display()const { cout<<"Pair12: ("<<x<<","<<y<<")\n"; }
    double distance()const { return hypot(x,y); }
};
Pair12 make_pair12(double a,double b) { Pair12 p; p.init(a,b); return p; }

/* ======== 13 ======== */
class Pair13 {
    double a,b;
public:
    bool init(double x,double y) {
        if(x<=0||y<=0) { cout<<"Ошибка: стороны<=0 Pair13\n"; return false;}
        a=x; b=y; return true;
    }
    bool read() {
        if(!(cin>>a>>b)) { cout<<"Ошибка ввода Pair13\n"; return false;}
        if(a<=0||b<=0) { cout<<"Ошибка: стороны<=0 Pair13\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair13: "<<a<<", "<<b<<"\n"; }
    double hypotenuse()const { return hypot(a,b); }
};
Pair13 make_pair13(double a,double b) { Pair13 p; p.init(a,b); return p; }

/* ======== 14 ======== */
class Pair14 {
    double sal;
    int days;
public:
    bool init(double s,int d) {
        if(s<0||d<0) { cout<<"Ошибка в Pair14\n"; return false;}
        sal=s; days=d; return true;
    }
    bool read() {
        if(!(cin>>sal>>days)) { cout<<"Ошибка ввода Pair14\n"; return false;}
        if(sal<0||days<0) { cout<<"Ошибка в Pair14\n"; return false;}
        return true;
    }
    void display()const { cout<<"Pair14: salary="<<sal<<" days="<<days<<"\n"; }
    double summa(int days_month)const {
        if(days_month<=0) { cout<<"Ошибка: дни<=0 Pair14\n"; return 0;}
        return sal/days_month*days;
    }
};
Pair14 make_pair14(double a,int b) { Pair14 p; p.init(a,b); return p; }

/* ======== 15 ======== */
class Pair15 {
    int mins;
    double pr;
public:
    bool init(int m,double p) {
        if(m<0||p<0) { cout<<"Ошибка Pair15\n"; return false;}
        mins=m; pr=p; return true;
    }
    bool read() { if(!(cin>>mins>>pr)) { cout<<"Ошибка ввода Pair15\n"; return false;} return init(mins,pr); }
    void display()const { cout<<"Pair15: "<<mins<<" * "<<pr<<"\n"; }
    double cost()const { return mins*pr; }
};
Pair15 make_pair15(int a,double b) { Pair15 p; p.init(a,b); return p; }

/* ======== 16 ======== */
class Pair16 {
    double ip,fp;
public:
    bool init(double a,double b) {
        if(b<0) { cout<<"Ошибка: frac<0 Pair16\n"; return false;}
        ip=a; fp=b; return true;
    }
    bool read() { if(!(cin>>ip>>fp)) { cout<<"Ошибка ввода Pair16\n"; return false;} return init(ip,fp); }
    void display()const { cout<<"Pair16: "<<ip<<" + "<<fp<<"\n"; }
    double multiply(double m)const { return (ip+fp)*m; }
};
Pair16 make_pair16(double a,double b) { Pair16 p; p.init(a,b); return p; }

/* ======== 17 ======== */
class Pair17 {
    int x,y;
    int W=1920,H=1080;
public:
    bool init(int a,int b) {
        if(a<0||b<0) { cout<<"Ошибка: отрицательные координаты Pair17\n"; return false;}
        x=a; y=b; return true;
    }
    bool read() {
        if(!(cin>>x>>y)) { cout<<"Ошибка ввода Pair17\n"; return false;}
        return init(x,y);
    }
    void display()const { cout<<"Pair17: ("<<x<<","<<y<<")\n"; }
    bool changex(int d) {
        long long nx=x+d;
        if(nx<0||nx>=W) { cout<<"Ошибка: выход за границы X Pair17\n"; return false;}
        x=nx; return true;
    }
    bool changey(int d) {
        long long ny=y+d;
        if(ny<0||ny>=H) { cout<<"Ошибка: выход за границы Y Pair17\n"; return false;}
        y=ny; return true;
    }
};
Pair17 make_pair17(int a,int b) { Pair17 p; p.init(a,b); return p; }

/* ======== 18 ======== */
class Pair18 {
    long long ip;
    unsigned long long fp;
public:
    bool init(long long a,unsigned long long b) { ip=a; fp=b; return true; }
    bool read() { if(!(cin>>ip>>fp)) { cout<<"Ошибка ввода Pair18\n"; return false;} return true; }
    void display()const { cout<<"Pair18: "<<ip<<" frac "<<fp<<"\n"; }

    long double multiply(long long m,unsigned digits=0)const {
        if(digits==0) {
            unsigned long long t=fp;
            while(t) { t/=10; digits++; }
        }
        long double val = ip + fp/(long double)pow(10,digits);
        return val*m;
    }
};
Pair18 make_pair18(long long a,unsigned long long b) { Pair18 p; p.init(a,b); return p; }

/* ======== 19 ======== */
class Pair19 {
    long long k,n;
public:
    bool init(long long a,long long b) {
        if(a<0||b<0||a>b) { cout<<"Ошибка Pair19\n"; return false;}
        k=a; n=b; return true;
    }
    bool read() { if(!(cin>>k>>n)) { cout<<"Ошибка ввода Pair19\n"; return false;} return init(k,n); }
    void display()const { cout<<"Pair19: C("<<n<<","<<k<<")\n"; }
    long double combination()const {
        long long K=k; if(K>n-K) K=n-K;
        long double r=1;
        for(long long i=1;i<=K;i++) {
            r*= (n-K+i);
            r/= i;
        }
        return r;
    }
};
Pair19 make_pair19(long long a,long long b) { Pair19 p; p.init(a,b); return p; }

/* ======== 20 ======== */
class Pair20 {
    double a0,r;
public:
    bool init(double a,double b) { a0=a; r=b; return true; }
    bool read() { if(!(cin>>a0>>r)) { cout<<"Ошибка ввода Pair20\n"; return false;} return true; }
    void display()const { cout<<"Pair20: a0="<<a0<<" r="<<r<<"\n"; }
    double elementj(unsigned long long j)const { return a0*pow(r,j); }
};
Pair20 make_pair20(double a,double b) { Pair20 p; p.init(a,b); return p; }


  






int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    while (true) {
        cout << "Выберите номер задачи (1–20):\n0 – выйти\n\nВаш выбор: ";
        int choice;
        cin >> choice;

        if (!cin) {
            cout << "Ошибка ввода!\n";
            return 0;
        }

        if (choice == 0) {
            cout << "Выход...\n";
            break;
        }

        if (choice < 1 || choice > 20) {
            cout << "Нет такого варианта!\n";
            continue;
        }

        cout << "\n--- Вариант " << choice << " ---\n\n";

        // ===============================================================
        
        switch (choice) {

        case 1: {
            Pair1 p; double a; int b;
            cout << "Введите a b: ";
            cin >> a >> b;
            if (p.init(a,b)) {
                p.display();
                cout << "power = " << p.power() << "\n";
            }
            break;
        }

        case 2: {
            Pair2 p; double a,b;
            cout << "Введите a b: ";
            cin >> a >> b;
            if (p.init(a,b)) {
                p.display();
                cout << "power = " << p.power() << "\n";
            }
            break;
        }

        case 3: {
            Pair3 p; long long x,y;
            cout << "Введите числитель и знаменатель: ";
            cin >> x >> y;
            if (p.init(x,y)) {
                p.display();
                cout << "ipart = " << p.ipart() << "\n";
            }
            break;
        }

        case 4: {
            Pair4 p; int d,c;
            cout << "Введите номинал, количество: ";
            cin >> d >> c;
            if (p.init(d,c)) {
                p.display();
                cout << "sum = " << p.summa() << "\n";
            }
            break;
        }

        case 5: {
            Pair5 p; double price; int qty;
            cout << "Введите цену и количество: ";
            cin >> price >> qty;
            if (p.init(price,qty)) {
                p.display();
                cout << "cost = " << p.cost() << "\n";
            }
            break;
        }

        case 6: {
            Pair6 p; int cal; double kg;
            cout << "Введите кал/100г и массу (кг): ";
            cin >> cal >> kg;
            if (p.init(cal,kg)) {
                p.display();
                cout << "calories = " << p.power() << "\n";
            }
            break;
        }

        case 7: {
            Pair7 p; double L,R,x;
            cout << "Введите L и R: ";
            cin >> L >> R;
            if (p.init(L,R)) {
                p.display();
                cout << "Введите число: ";
                cin >> x;
                cout << (p.rangecheck(x) ? "В диапазоне\n" : "НЕ в диапазоне\n");
            }
            break;
        }

        case 8: {
            Pair8 p; int L,R,x;
            cout << "Введите L и R: ";
            cin >> L >> R;
            if (p.init(L,R)) {
                p.display();
                cout << "Введите число: ";
                cin >> x;
                cout << (p.rangecheck(x) ? "В диапазоне\n" : "НЕ в диапазоне\n");
            }
            break;
        }

        case 9: {
            Pair9 p; int h,m;
            cout << "Введите часы и минуты: ";
            cin >> h >> m;
            if (p.init(h,m)) {
                p.display();
                cout << "minutes = " << p.minutes() << "\n";
            }
            break;
        }

        case 10: {
            Pair10 p; double A,B,x;
            cout << "Введите A B: ";
            cin >> A >> B;
            if (p.init(A,B)) {
                p.display();
                cout << "Введите x: ";
                cin >> x;
                cout << "f(x) = " << p.function(x) << "\n";
            }
            break;
        }

        case 11: {
            Pair11 p; double A,B;
            cout << "Введите A B: ";
            cin >> A >> B;
            if (p.init(A,B)) {
                p.display();
                cout << "root = " << p.root() << "\n";
            }
            break;
        }

        case 12: {
            Pair12 p; double x,y;
            cout << "Введите x y: ";
            cin >> x >> y;
            if (p.init(x,y)) {
                p.display();
                cout << "distance = " << p.distance() << "\n";
            }
            break;
        }

        case 13: {
            Pair13 p; double a,b;
            cout << "Введите катеты a b: ";
            cin >> a >> b;
            if (p.init(a,b)) {
                p.display();
                cout << "hypotenuse = " << p.hypotenuse() << "\n";
            }
            break;
        }

        case 14: {
            Pair14 p; double sal; int days;
            cout << "Введите зарплату и отработанные дни: ";
            cin >> sal >> days;
            if (p.init(sal,days)) {
                p.display();
                cout << "Введите дней в месяце: ";
                int m; cin >> m;
                cout << "sum = " << p.summa(m) << "\n";
            }
            break;
        }

        case 15: {
            Pair15 p; int mins; double pr;
            cout << "Введите минуты и цену: ";
            cin >> mins >> pr;
            if (p.init(mins,pr)) {
                p.display();
                cout << "cost = " << p.cost() << "\n";
            }
            break;
        }

        case 16: {
            Pair16 p; double ip,fp;
            cout << "Введите целую и дробную часть: ";
            cin >> ip >> fp;
            if (p.init(ip,fp)) {
                p.display();
                double m;
                cout << "Введите множитель: ";
                cin >> m;
                cout << "result = " << p.multiply(m) << "\n";
            }
            break;
        }

        case 17: {
            Pair17 p; int x,y;
            cout << "Введите x y: ";
            cin >> x >> y;
            if (p.init(x,y)) {
                p.display();
                int dx,dy;
                cout << "Введите dx: ";
                cin >> dx;
                p.changex(dx);
                cout << "Введите dy: ";
                cin >> dy;
                p.changey(dy);
                p.display();
            }
            break;
        }

        case 18: {
            Pair18 p; long long ip; unsigned long long fp;
            cout << "Введите целую и дробную части: ";
            cin >> ip >> fp;
            if (p.init(ip,fp)) {
                p.display();
                long long m; unsigned d;
                cout << "Введите множитель: ";
                cin >> m;
                cout << "Введите число знаков дроби (или 0): ";
                cin >> d;
                cout << "result = " << (double)p.multiply(m,d) << "\n";
            }
            break;
        }

        case 19: {
            Pair19 p; long long k,n;
            cout << "Введите k n: ";
            cin >> k >> n;
            if (p.init(k,n)) {
                p.display();
                cout << "C = " << (double)p.combination() << "\n";
            }
            break;
        }

        case 20: {
            Pair20 p; double a0,r;
            cout << "Введите a0 r: ";
            cin >> a0 >> r;
            if (p.init(a0,r)) {
                p.display();
                unsigned long long j;
                cout << "Введите номер j: ";
                cin >> j;
                cout << "element = " << p.elementj(j) << "\n";
            }
            break;
        }

        } // switch

    } // while

    return 0;
}


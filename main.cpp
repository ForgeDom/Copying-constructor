//#include <iostream>
//using namespace std;
//
//class Point
//{
//    static int count;
//public:
//    int* x = nullptr;
//    int* y = nullptr;
//    Point()
//    {
//        x = new int{ 0 };
//        y = new int{ 0 };
//        Point::inc_count();
//    }
//    Point(int x, int y) : Point()
//    {
//        this->x = new int{ x };
//        this->y = new int{ y };
//    }
//    Point(const Point& p)
//    {
//        if (x != nullptr)
//            delete x;
//        if (y != nullptr)
//            delete y;
//        x = new int{ *p.x };
//        y = new int{ *p.y };
//        Point::inc_count();
//    }
//
//    Point(const Point&& p)
//    {
//        if (x != nullptr)
//            delete x;
//        if (y != nullptr)
//            delete y;
//        x = new int{ *p.x };
//        y = new int{ *p.y };
//        Point::inc_count();
//        delete p.y;
//        delete p.x;
//    }
//
//    //operator =
//    Point& operator=(const Point& p)
//    {
//        if (this == &p)
//            return *this;
//        if (x != nullptr)
//            delete x;
//        if (y != nullptr)
//            delete y;
//        x = new int{ *p.x };
//        y = new int{ *p.y };
//        return *this;
//    }
//
//
//    static void inc_count()
//    {
//        count++;
//    }
//
//    static void showCount()
//    {
//        cout << "Count = " << count << endl;
//    }
//
//    void get()
//    {
//        cout << "x = " << *x << " y = " << *y << endl;
//    }
//
//    ~Point()
//    {
//        delete x, y;
//    }
//};
//
//int Point::count = 0;
//
//int main()
//{
//    Point* p1 = new Point(5, 5);
//    Point* p2 = new Point(move(*p1));
//    p1->get();
//    p2->get();
//    Point::showCount();
//}
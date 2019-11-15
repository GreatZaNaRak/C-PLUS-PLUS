#ifndef HELLO_H
#define HELLO_H


class Hello
{
    public:
        Hello();
        virtual ~Hello();
        void greet()
        {
            cout << "Hello" << endl;
        }

    protected:

    private:
};

#endif // HELLO_H

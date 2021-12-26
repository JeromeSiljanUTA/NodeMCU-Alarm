#ifndef Display_h
#define Display_h

class Display{
    private:
        int pins[4];
    public:
        Display(int pin0, int pin1, int pin2, int pin3);
        void writeNum(int num);
};

#endif

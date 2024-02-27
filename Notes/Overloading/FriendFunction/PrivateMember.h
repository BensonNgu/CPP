#ifndef PRIVATEMEMBER_H
#define PRIVATEMEMBER_H

class Example{
    friend void release(Example *ex);
    private:
        ~Example();
};

#endif
/* The ISP states that clients should not be forced to depend on interfaces they do not use.
 Instead of having one large interface with many unrelated methods, 
 it's better to split it into smaller, specific interfaces. */

 #include <iostream>
 using namespace std;

class NTFS
{
    public : 
    virtual void read_NTFS() = 0;
};

class ext4
{
    public : 
    virtual void read_ext4() = 0;
};

class Windows : public NTFS
{
    public : 
    void read_NTFS() override{
        cout << "NTFS file read success !" << endl;
    }
};

class Linux : public NTFS, public ext4{
    public : 
    void read_NTFS() override
    {
        cout << "NTFS file read success !" << endl;
    }

    void read_ext4() override{
        cout << "EXT4 file read success !" << endl;
    }
};


int main()
{
    Windows *w1 = new Windows;
    Linux * l1 = new Linux;

    w1->read_NTFS();
    l1->read_NTFS();
    l1->read_ext4();

    delete w1;
    delete l1;
}
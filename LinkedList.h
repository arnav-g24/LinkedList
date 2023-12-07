#ifndef LINKEDLIST
#define LINKEDLIST

//struct Node to define the Node for the list
struct Node{
    public:
        int value;                                      // just an integer for example (can be any data required)
        Node* next;                                     // the next node or the lint

        Node(int num = 0): value{num}, next{nullptr}{}; // default constructor, sets value to 0 if no parameter input
                                                        // Next Node is automatically set to nullptr
        
        bool operator<(Node &other){                   // for example only
            if(this->value < other.value){              // implemented to sort the LinkedList in ascending order
                return true;                            
            }else{
                return false;
            }
        }
};

class LinkedList{
    private:
        //any private variables or functions go here (not accessible by user)
        void clear();               // clear function used in the destructor

    public:
        //all public variables or functions (accessible by user)
        Node* head;                 // head node (start)
        Node* tail;                 // tail node (end)
        int length;                 // store a length value to track number of Nodes

        LinkedList();               // default constructor
        void insert(int val);       // insert value into LinkedList
        void print();               // to print out the list

        //----------------------------rule of three----------------------------------
        ~LinkedList();                                   // destructor
        LinkedList(const LinkedList &src);                  // copy constructor
        LinkedList& operator=(const LinkedList &src);       // copy assignment
        //---------------------------------------------------------------------------
};

#endif


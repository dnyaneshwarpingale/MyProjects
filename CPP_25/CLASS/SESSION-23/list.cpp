class node
{
    friend class list;
    private:
        int data;
        node* prev;
        node* next;
        node(int _data = 0 ): data(_data)
        {

        }
};

class list
{
    private:
        node* head_node;

    public:
        list():head_node(new node)
        {

        }
};

int main(void)
{
    node* pNode = new node;
}
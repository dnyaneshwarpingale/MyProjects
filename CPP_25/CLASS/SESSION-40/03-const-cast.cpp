/*
    use case
    To discard const qualifier
    or to temporarily assign const qualifier
*/

class Test
{
    private:
        int num;
        int getter_counter;
    public:
        Test() : num(100)
        {

        }

        int get() const
        {
            this-> getter_counter += 1; // Error
            ++getter_counter; // Error

            const_cast<Test*>(this)->getter_counter += 1;
            return num;

        }
    
};

void test_1();
void test_2();

int main()
{
    test_1();
    test_2();
    return 0;

}

void test_1()
{
    const int num = 100;

    *(int*)(&num) = 200; // Discard const qualifier c -style syntax
    *static_cast<int*>(&num) = 200; // Error

    *reinterpret_cast<int*>(&num) = 200; // Surprise -> Even reinterpret_cast fails you
    *const_cast<int*>(&num) = 200; // This Will work !

}

void qsort(const void* arr, size_t size, size_t mem_size, int(*pfn_compare)(const void* o1, const void* o2))
{

}

struct Date
{
    int day, month, year;
};

int compare(const struct Date* p1, const struct Date* p2)
{

}

typedef int(&pfn_compare_t)(const void* , const void*);
bool search(const struct Date* arr, const struct Date* search_instance);

void test_2()
{
    struct Date date_arr[10];
    struct Date epoch = {1,1,1970};

    search(
        const_cast<const struct Date*>(date_arr),
        const_cast<const struct Date*>(&epoch)  );

    qsort(
        const_cast <const void*>(reinterpret_cast<void*>(date_arr)),
        10,
        sizeof(struct Date),
        reinterpret_cast<pfn_compare_t>(compare)
    );
}
typedef struct nodeRecord {
    int Data;
    struct nodeRecord* Next;
} node;

typedef node* Nptr;

typedef struct {
    int Count;
    Nptr Head;
} listType;

void Add(listType *Lptr);
void Insert(listType *Lptr, int Position, int Item);
void Delete(listType *Lptr, int Position);
int Retrieve(listType *Lptr, int Position);
void Update(listType *Lptr, int Position, int Item);
void Init(listType *Lptr);
bool IsEmpty(listType *Lptr);
int Length(listType *Lptr);
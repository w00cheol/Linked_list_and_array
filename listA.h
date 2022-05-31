#define MAX 100
typedef struct {
    int Count; // Count 값: 0, 1, 2 <-- 리스트안에 있는 의미 있는 값의 개수
    int Data[MAX];
} listType;

// Lptr이 가리키고 있는 리스트를 초기화
void Init(listType *Lptr);

// Lptr이 가리키고 있는 리스트가 비어있으면 '참'을 비어있지 않으면 '거짓'을 반환
bool IsEmpty(listType *Lptr);

// Lptr이 가리키고 있는 리스트에 마지막에 계속적으로 원소 추가
void Add(listType *Lptr);

// Lptr이 가리키고 있는 리스트에 들어있는 의미있는 값의 개수를 반환
int Length(listType *Lptr);

// Lptr이 가리키고 있는 리스트의 Position번째에 Item 값을 삽입
void Insert(listType *Lptr, int Position, int Item);

// Lptr이 가리키고 있는 리스트의 Position번째 내용을 삭제
void Delete(listType *Lptr, int Position);

// Lptr이 가리키고 있는 리스트의 Position번째에 Item 값으로 변경
void Update(listType *Lptr, int Position, int Item);

// Lptr이 가리키고 있는 리스트의 Position번째 값을 반환
int Retrieve(listType *Lptr, int Position);
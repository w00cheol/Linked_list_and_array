# C언어에서 두 가지 방법으로 리스트 구현 (1. 배열 2. 연결 리스트(노드))

---
#### 동작과정
---
1. 리스트 형태의 구조체 초기화
2. 동적 메모리를 할당 / 해제하여 원소 추가 / 삭제



---
#### 적용기술
---


- Dynamic memory allocation
- Linkedlist
- Arraylist



---
#### 실행방법
---


1. 이 레포지토리 폴더 안에서 터미널을 실행합니다.


2. 다음 명령어로 배열을 이용한 리스트 프로그램을 구동시킵니다.

<pre> ./listA </pre>


3. 다음 명령어로 배열을 이용한 리스트 프로그램을 구동시킵니다.

<pre> ./listP </pre>


4. <strong>만약 프로그램이 정상적으로 작동하지 않는다면, 아래 명령어를 실행 한 후 재시도합니다.</strong>

 <pre>
 make clean

 make listA

 make listP
</pre>





---
#### 리스트 초기화
---
![](https://user-images.githubusercontent.com/53927414/171184623-28111d82-d907-40b0-9503-b1a865f26706.png)

* 리스트를 초기화합니다.


---
#### 공백여부 확인
---
![](https://user-images.githubusercontent.com/53927414/171184663-b7043f61-e994-4299-bc01-7bee39fae5c4.png)

* 리스트가 비어있는지 확인합니다.

* 초기화 후, 아직 아무 원소도 삽입하지 않은 상태이므로, count가 0입니다.

* 따라서 리스트가 비어있다고 출력합니다.



---
#### 원소 등록
---
![](https://user-images.githubusercontent.com/53927414/171184676-aff43c27-da7c-4b79-8f1f-d8f3301cf75a.png)

* 1번째 원소로 30, 2번째 원소로 25, 3번째 원소로 50을 등록합니다.

* 사용자가 X를 입력하면, 원소 등록을 종료합니다.




---
#### 원소 개수 확인
---
![](https://user-images.githubusercontent.com/53927414/171184695-7d1de0ca-f692-4201-a1b9-e1dbeb21634a.png)

* 원소를 3개 등록했기 때문에, 3을 출력합니다.




---
#### 원소 삽입
---
![](https://user-images.githubusercontent.com/53927414/171184715-c78379be-30ac-4bec-a362-1f117524b3b7.png)

* 원소를 추가하기 전, 리스트에 있는 원소는, 30, 25, 50입니다.

* 3번째 원소로 100을 추가합니다.

* 현재 리스트의 원소는 30, 25, 100, 50 이 됩니다.




---
#### 원소 삭제
---
![](https://user-images.githubusercontent.com/53927414/171184748-ff317556-a83c-448f-b443-91b5a2f98770.png)

* 첫 번째 원소를 제거합니다.

* 따라서 현재 리스트의 원소는 25, 100, 50 이 됩니다.



---
#### 원소 변경
---
![](https://user-images.githubusercontent.com/53927414/171184768-fa56cd18-56f8-46f1-8626-692abb14ce16.png)

* 1번째 원소를 77로 변경합니다.

* 따라서 현재 리스트의 원소는 77, 100, 50 이 됩니다.



---
#### 원소 검색
---
![](https://user-images.githubusercontent.com/53927414/171184815-71aaf2b2-6b7c-4593-af3c-3215ca7281f4.png)

* 2번째 원소를 검색합니다.

* 77, 100, 50 이 저장되어 있었기 때문에 2번째 원소인 100을 출력합니다.




---
#### 프로그램 종료
---
![](https://user-images.githubusercontent.com/53927414/171184845-475a8a5e-b40e-4261-9a86-5beb77f658bd.png)

* 프로그램을 종료합니다.
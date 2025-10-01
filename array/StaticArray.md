# Static Array (정적 배열)

_C++을 기반으로 작성된 글_

### 정의

정적 배열은 컴파일 시점에 크기와 메모리가 결정되는 배열이다.

### 특징

- 컴파일 시점에 크기가 결정 되므로 런타임 시점에서 크기를 변경할 수 없다.
- C++의 기본 배열은 자신의 크기를 모른다.(JAVA의 .length와 같이 내부 변수 접근을 CPP에서는 못한다.)
- 초기화를 안하면 Junk value가 들어있다.
- 배열 이름은 사실상 첫 번째 원소 주소이다.

### 시간 복잡도

##### Read

O(1)
배열은 `arr[i] = *(arr + i)` 포인터 연산 한 번으로 바로 접근 가능.

##### Insert/Delete

C-style 배열은 삽입/삭제를 직접 지원하지 않지만, 원소 이동을 통해 구현할 수 있으며 이 경우 시간복잡도는 O(n)이다.

##### Search

배열이 정렬돼 있지 않다면 선형 탐색으로 O(n), 정렬돼 있다면 이진 탐색으로 O(log n) 가능.

### 구현 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T, int SIZE>
class StaticArray
{
private:
    T data[SIZE];
    int length;

public:
    StaticArray() : length(0) {}
    int size() const { return length; }
    int capacity() const { return SIZE; }

    bool push_back(const T &value)
    {
        if (length >= SIZE)
        {
            cout << "Error: 배열이 가득 참" << "\n";
            return false;
        }
        data[length++] = value;
        return true;
    }

    // 특정 위치에 삽입
    bool insert(int index, const T &value)
    {
        // 삽입 불가 length가 정적 배열 사이즈 이상, 접근 index가  OOB거나 음수.
        if (length >= SIZE || index < 0 || index >= SIZE)
        {
            cout << "Error: 삽입할 수 없음" << "\n";
            return false;
        }
        // 한칸씩 뒤로 밀기
        for (int i = index; i < length + 1; i++)
            data[i + 1] = data[i];
        data[index] = value;
        length++;
        return true;
    }

    // 삭제
    bool remove(int index)
    {
        // 삭제 불가
        if (index < 0 || index > length)
        {
            cout << "Error: 삭제 불가" << "\n";
            return false;
        }
        // 한칸씩 당겨서 원소 삭제
        for (int i = length; i > index; i--)
            data[i - 1] = data[i];
        length--;
        return true;
    }

    // 원소 접근 (읽기/쓰기)
    T &operator[](int index)
    {
        if (index < 0 || index >= length)
        {
            throw out_of_range("OOB");
        }
        return data[index];
    }

    // 출력
    void print() const
    {
        cout << "[ ";
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << "]" << endl;
    }
};

int main(void)
{
    StaticArray<int, 5> sa;
    sa.push_back(1);
    sa.push_back(3);
    sa.push_back(5);
    sa.push_back(7);

    cout << sa.size() << "\n";
    cout << sa.capacity() << "\n";
    sa.print();

    sa.remove(0);
    sa.remove(1);

    cout << sa.size() << "\n";
    cout << sa.capacity() << "\n";
    sa.print();

    cout << sa[0] << "\n";

    return 0;
}

```

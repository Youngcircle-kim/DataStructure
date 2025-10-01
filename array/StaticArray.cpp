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
            throw out_of_range("index 초과");
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
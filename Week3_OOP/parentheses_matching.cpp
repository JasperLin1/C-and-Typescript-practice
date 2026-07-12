#include <iostream>
#include <string>

// ========================================================
// 這是我們剛剛寫好的 Stack 類別 (直接拿來用！)
// ========================================================
class Stack {
private:
    char* arr; // 這次改為儲存 char，因為括號是字元！
    int capacity;
    int topIndex;

public:
    Stack(int cap) {
        capacity = cap;
        topIndex = -1;
        arr = new char[capacity];
    }
    ~Stack() {
        delete[] arr;
        arr = nullptr;
    }
    void push(char val) {
        if (topIndex < capacity - 1) {
            topIndex++;
            arr[topIndex] = val;
        }
    }
    char pop() {
        if (isEmpty()) return '\0';
        char val = arr[topIndex];
        topIndex--;
        return val;
    }
    char peek() {
        if (isEmpty()) return '\0';
        return arr[topIndex];
    }
    bool isEmpty() {
        return topIndex == -1;
    }
};

// ========================================================
// 🎯 演算法實戰：括號匹配檢查 (Valid Parentheses)
// ========================================================
// 這是 LeetCode 第 20 題的經典題目！
// 輸入一個只包含 '(', ')', '[', ']', '{', '}' 的字串，
// 檢查這些括號是否「成對且順序正確」。
//
// 演算法邏輯：
// 1. 從左到右遍歷字串中的每個字元。
// 2. 如果遇到左括號 '(', '[', '{' ➡️ 把它 `push` 壓入堆疊。
// 3. 如果遇到右括號 ')', ']', '}' ➡️ 
//    a. 先檢查堆疊是否為空。若空，代表沒有對應的左括號，回傳 false。
//    b. `peek` 堆疊最上方的左括號，看是否與目前的右括號配對 (例如 '(' 配 ')' )。
//    c. 若配對成功，將左括號 `pop` 彈出，繼續往下看。
//    d. 若配對失敗，代表順序錯誤，回傳 false。
// 4. 跑完字串後，如果堆疊「是空的」，代表全部配對成功，回傳 true；否則回傳 false。

// TODO: 請實作 isValidParentheses 函式
bool isValidParentheses(std::string str) {
    // 宣告一個容量與字串長度相同的堆疊
    Stack s(str.length());

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i]; // 當前字元

        // 1. 如果是左括號，請 push 進堆疊
        // 關鍵修正：在 C++ 中，不能用逗號隔開寫 `ch == '(', '[', '{'`。
        // 必須用邏輯或 `||` (OR) 將條件一個個連起來！
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        }
        
        // 2. 如果是右括號
        // 說明：是的！因為不同的右括號對應不同的左括號，寫成三個 `if / else if` 是最清晰、最不易出錯的寫法！
        else if (ch == ')') {
            // 如果堆疊是空的（沒有左括號配對），或者最上面不是配對的 '('，就宣告失敗
            if (s.isEmpty() || s.peek() != '(') {
                return false; 
            }
            s.pop(); // 配對成功，把左括號彈出
        } 
        else if (ch == ']') {
            if (s.isEmpty() || s.peek() != '[') {
                return false;
            }
            s.pop();
        } 
        else if (ch == '}') {
            if (s.isEmpty() || s.peek() != '{') {
                return false;
            }
            s.pop();
        }
    }

    // 3. 檢查最後堆疊是否全部配對完畢 (是否為空)
    // 說明：如果堆疊是空的，代表所有的左括號都成功配對彈出了，字串就是有效的 (true)；
    // 如果裡面還有殘留的左括號，代表無效 (false)。
    // 我們可以直接回傳 `s.isEmpty()` 的結果！
    return s.isEmpty();
}

int main() {
    std::cout << "=== 測試括號匹配演算法 ===" << std::endl;

    std::string test1 = "()";
    std::string test2 = "()[]{}";
    std::string test3 = "(]";
    std::string test4 = "([)]";
    std::string test5 = "{[()]}";

    std::cout << test1 << " : " << (isValidParentheses(test1) ? "有效 (Valid)" : "無效 (Invalid)") << " (預期: 有效)" << std::endl;
    std::cout << test2 << " : " << (isValidParentheses(test2) ? "有效 (Valid)" : "無效 (Invalid)") << " (預期: 有效)" << std::endl;
    std::cout << test3 << " : " << (isValidParentheses(test3) ? "有效 (Valid)" : "無效 (Invalid)") << " (預期: 無效)" << std::endl;
    std::cout << test4 << " : " << (isValidParentheses(test4) ? "有效 (Valid)" : "無效 (Invalid)") << " (預期: 無效)" << std::endl;
    std::cout << test5 << " : " << (isValidParentheses(test5) ? "有效 (Valid)" : "無效 (Invalid)") << " (預期: 有效)" << std::endl;

    return 0;
}

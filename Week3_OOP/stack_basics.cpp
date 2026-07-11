#include <iostream>

// ========================================================
// 知識點: 什麼是堆疊 (Stack)？
// ========================================================
// 堆疊是一種「後進先出 (LIFO - Last In First Out)」的資料結構。
// 想像一疊盤子：
// - 你只能把新盤子放到最上面 (Push)
// - 你拿盤子也只能從最上面拿 (Pop)
// - 你看盤子也只能看到最上面那一個 (Top/Peek)
//
// 本次練習：我們將使用物件導向 (Class) 的封裝特性，
// 在內部使用「動態陣列 (new[])」來手動實作一個 Stack 類別！

class Stack {
private:
    int* arr;         // 指向動態陣列的指標 (用來存堆疊裡的資料)
    int capacity;     // 堆疊的最大容量
    int topIndex;     // 記錄目前最上方元素的位置 (索引)。如果堆疊是空的，設為 -1。

public:
    // TODO 1: 實作建構子 (Constructor)
    // 提示：
    // - 接收一個參數 `int cap` 代表容量。
    // - 初始化 `capacity = cap;`。
    // - 初始化 `topIndex = -1;` (代表一開始沒有任何資料)。
    // - 在 Heap 中動態配置一個大小為 capacity 的整數陣列，並讓 `arr` 指向它。
    // [在此寫下建構子代碼]
    Stack(int cap) {
        
    }

    // TODO 2: 實作解構子 (Destructor)
    // 提示：
    // - 當 Stack 物件死亡時，必須主動釋放內部動態配置的陣列記憶體，防止記憶體洩漏！
    // - 使用 `delete[] arr;`。
    // [在此寫下解構子代碼]
    ~Stack() {
        
    }

    // TODO 3: 實作 Push (將資料壓入堆疊)
    // 提示：
    // - 函數名稱：`void push(int val)`。
    // - 先檢查堆疊是否滿了：如果 `topIndex == capacity - 1`，印出 "Stack Overflow!" 並直接結束。
    // - 如果沒滿：將 `topIndex` 加 1，然後把 `val` 放入陣列的該位置：`arr[topIndex] = val;`。
    // [在此寫下 push 函式]
    void push(int val) {
        
    }

    // TODO 4: 實作 Pop (將最上方資料彈出並回傳)
    // 提示：
    // - 函數名稱：`int pop()`。
    // - 先檢查堆疊是否為空：如果 `isEmpty()` 為真，印出 "Stack Underflow!" 並回傳 -1。
    // - 如果不為空：
    //   1. 先用一個變數記錄最上方的數值：`int topVal = arr[topIndex];`
    //   2. 將 `topIndex` 減 1 (代表最上方的資料被移除了)。
    //   3. 回傳剛才記錄的 `topVal`。
    // [在此寫下 pop 函式]
    int pop() {
        return 0; // 請修改它
    }

    // TODO 5: 實作 Peek/Top (只看最上方資料，但不彈出)
    // 提示：
    // - 函數名稱：`int peek()`。
    // - 如果堆疊為空，回傳 -1。
    // - 否則，回傳目前最上方位置的資料：`arr[topIndex]`。
    // [在此寫下 peek 函式]
    int peek() {
        return 0; // 請修改它
    }

    // TODO 6: 實作判斷是否為空的公開函式
    // 提示：
    // - 函數名稱：`bool isEmpty()`。
    // - 當 `topIndex == -1` 時回傳 true，否則回傳 false。
    // [在此寫下 isEmpty 函式]
    bool isEmpty() {
        return false; // 請修改它
    }
};

int main() {
    std::cout << "=== 創建一個容量為 3 的堆疊 ===" << std::endl;
    // 宣告一個容量為 3 的 Stack 物件 (在 Stack 記憶體中宣告，但內部陣列在 Heap 中)
    Stack myStack(3);

    std::cout << "--- 測試 Push 資料 ---" << std::endl;
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // 嘗試推入第 4 個資料 (應該會爆掉，顯示 Stack Overflow!)
    std::cout << "嘗試推入第 4 個資料 (40)..." << std::endl;
    myStack.push(40);

    std::cout << "\n--- 測試 Peek (看最上方資料) ---" << std::endl;
    std::cout << "目前最上方的資料是 (應該是 30): " << myStack.peek() << std::endl;

    std::cout << "\n--- 測試 Pop (後進先出彈出資料) ---" << std::endl;
    // 解除下方註解進行測試：
    /*
    while (!myStack.isEmpty()) {
        std::cout << "彈出資料: " << myStack.pop() << std::endl;
    }
    */

    // 再次嘗試彈出 (應該會顯示 Stack Underflow!)
    // std::cout << "再次嘗試彈出: " << myStack.pop() << std::endl;

    return 0;
}

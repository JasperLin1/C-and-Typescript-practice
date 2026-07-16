#include <iostream>

// ========================================================
// LeetCode 官方的單向鏈結串列節點定義 (ListNode)
// ========================================================
struct ListNode {
    int val;        // 儲存的數值
    ListNode* next; // 指向下一格的指標

    // 🔎 說明：成員初始化列表 (Member Initializer List)
    // 這一行 `ListNode(int x) : val(x), next(nullptr) {}` 是 C++ 的建構子。
    // 冒號後面的 `: val(x), next(nullptr)` 是一個縮寫語法，相當於：
    //   ListNode(int x) {
    //       val = x;
    //       next = nullptr;
    //   }
    // 它代表：當我們執行 `new ListNode(5)` 創建新節點時，會自動把 val 設為 5，並把下一站 next 設為 nullptr。
    // 這種冒號寫法在 C++ 中執行效率更高，是標準的寫法！
    ListNode(int x) : val(x), next(nullptr) {}
};

// ========================================================
// 🎯 LeetCode 第 206 題：Reverse Linked List (反轉鏈結串列)
// ========================================================
// 題目描述：
// 給你一個單向鏈結串列的頭節點 `head`，請將該串列反轉，並回傳反轉後的頭節點。
//
// 範例：
// 輸入：1 -> 2 -> 3 -> nullptr
// 輸出：3 -> 2 -> 1 -> nullptr
//
// --------------------------------------------------------
// 💡 演算法思維 (三指針法)：
// 要把 `1 -> 2 -> 3` 變成 `3 -> 2 -> 1`，我們不能直接改 pointer，否則會斷掉找不到後面的節點。
// 我們需要三個指針來輔助：
// 1. `prev` (前一個節點) ➡️ 一開始設為 nullptr (因為反轉後頭節點 1 的下一站會是 nullptr)
// 2. `curr` (目前節點) ➡️ 一開始指著 head (也就是 1)
// 3. `nextTemp` (臨時記錄下一站的指標)
//
// 每一輪迴圈的魔術步驟：
// - 第一步：先用 `nextTemp` 記下下一站：`nextTemp = curr->next;` (例如：記下 2 的位置)
// - 第二步：把當前節點指回前一個節點：`curr->next = prev;` (把 1 指向 nullptr，成功斷開並反轉！)
// - 第三步：`prev` 往前走一步：`prev = curr;` (prev 走到 1)
// - 第四步：`curr` 往前走一步：`curr = nextTemp;` (curr 走到 2)
//
// 重複這個過程，直到 `curr` 走到 nullptr 為止，這時 `prev` 就會剛好指著新的頭節點 (3)！

// TODO: 請實作 reverseList 函式
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        // [在此寫下反轉迴圈的四個魔術步驟！]
        // 1. 記錄下一站：
        ListNode* next = curr -> next;
        // 2. 當前節點指向前一個節點：
        curr -> next = prev;
        // 3. prev 指針移動到當前位置：
        prev = curr;
        // 4. curr 指針移動到下一站：
        curr = next;
        
    }

    // 5. 回傳反轉後的頭節點
    // 關鍵修正：反轉後，原本的尾節點變成了新的頭節點，而此時 prev 剛好指著它！
    return prev; 
}

// ========================================================
// 🔎 說明：輔助函式 (Helper Function) ── 印出鏈結串列
// ========================================================
// 這是一個簡單的走訪 (Traversal) 函式：
// 1. 傳入一個頭節點指標 `head`。
// 2. 宣告一個移動指標 `temp` 指向起點。
// 3. 只要 `temp` 還不是空地址，就印出當前值，並用 `temp = temp->next` 走向下一格。
// 4. 最後印出 "nullptr" 代表火車尾。
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != nullptr) {
        std::cout << temp->val << " -> ";
        temp = temp->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    std::cout << "=== 測試 LeetCode 206: Reverse Linked List ===" << std::endl;

    // 建立鏈結串列：1 -> 2 -> 3 -> nullptr
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    std::cout << "原始串列: ";
    printList(head);

    // 呼叫反轉
    ListNode* reversedHead = reverseList(head);

    std::cout << "反轉後串列: ";
    printList(reversedHead);

    // 記憶體清理 (釋放反轉後的串列)
    ListNode* curr = reversedHead;
    while (curr != nullptr) {
        ListNode* next = curr->next;
        delete curr;
        curr = next;
    }

    return 0;
}

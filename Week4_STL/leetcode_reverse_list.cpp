#include <iostream>

// ========================================================
// LeetCode 官方的單向鏈結串列節點定義 (ListNode)
// ========================================================
struct ListNode {
    int val;
    ListNode* next;
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
        
        // 2. 當前節點指向前一個節點：
        
        // 3. prev 指針移動到當前位置：
        
        // 4. curr 指針移動到下一站：
        
    }

    // 5. 回傳反轉後的頭節點
    return nullptr; // 請修改它
}

// 輔助函式：印出鏈結串列
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

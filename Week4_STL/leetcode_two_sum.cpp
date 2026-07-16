#include <iostream>
#include <vector>
#include <unordered_map> // 核心：我們將使用哈希表來將 O(N^2) 優化到 O(N)！

// ========================================================
// 🎯 LeetCode 第 1 題：Two Sum (兩數之和)
// ========================================================
// 題目描述：
// 給你一個整數陣列 `nums` 和一個目標值 `target`，
// 請在該陣列中找出「相加等於目標值」的那兩個數字，並回傳它們的「索引 (index)」。
//
// 範例：
// 輸入：nums = [2, 7, 11, 15], target = 9
// 輸出：[0, 1] (因為 nums[0] + nums[1] == 9)
//
// --------------------------------------------------------
// 💡 演算法思維：
// 1. 暴力法 (Brute Force)：用兩個 nested for 迴圈兩兩相加，時間複雜度是 O(N^2)。
// 2. 哈希表法 (Hash Table)：我們只用一個迴圈遍歷陣列。
//    當我們走到數字 x 時，我們去問哈希表：「裡面有沒有記錄過 (target - x) 這個數字？」
//    - 如果有 ➡️ 找到了！回傳「(target - x) 的索引」和「目前 x 的索引」。
//    - 如果沒有 ➡️ 把目前的數字 x 和它的索引存進哈希表中，繼續往下走。
//    因為哈希表查詢只需要 O(1) 時間，因此整體時間複雜度只要 O(N)！

// TODO: 請實作 twoSum 函式
std::vector<int> twoSum(std::vector<int>& nums, int target) {
    // 宣告一個哈希表：Key 是「陣列中的數值」，Value 是「該數值的索引 (Index)」
    std::unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i]; // 目前的數字
        int complement = target - x; // 我們想找的對手數字

        // 提示：如何檢查 complement 是否存在於 numMap 中？
        // 使用 `numMap.find(complement)`。
        // 如果 `find` 的結果不等於 `numMap.end()`，代表找到了！
        // [在此寫下 if / else 判斷與回傳代碼]
        // 1. 判斷 complement 是否在 map 中：
        if(numMap.find(complement) != numMap.end()){
            return {numMap[complement],i};
        }else{
            numMap[x] = i; //這個寫法就是將目前的數字 x 與它的索引 i 存入 map ?
        }
            // 2. 如果在：回傳一個包含 {numMap[complement], i} 的 vector：
            //    語法：`return {numMap[complement], i};`
            
        

        // 3. 如果不在：將目前的數字 x 與它的索引 i 存入 map：
        //    語法：`numMap[x] = i;`
        
    }

    return {}; // 若沒找到，回傳空陣列
}

int main() {
    std::cout << "=== 測試 LeetCode 1: Two Sum ===" << std::endl;

    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = twoSum(nums1, target1);

    std::cout << "測試 1 結果: ";
    if (result1.size() == 2) {
        std::cout << "[" << result1[0] << ", " << result1[1] << "] (預期: [0, 1])" << std::endl;
    } else {
        std::cout << "未找到解！" << std::endl;
    }

    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = twoSum(nums2, target2);

    std::cout << "測試 2 結果: ";
    if (result2.size() == 2) {
        std::cout << "[" << result2[0] << ", " << result2[1] << "] (預期: [1, 2])" << std::endl;
    } else {
        std::cout << "未找到解！" << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> // 核心：使用 unordered_map 必須引入此標頭檔
#include <map>           // 核心：使用 map 必須引入此標頭檔

// ========================================================
// 🎯 Week 4: Day 25 - STL 哈希表 (std::unordered_map) 基礎
// ========================================================
// 以前我們的陣列/vector，只能用「整數數字 (0, 1, 2...)」作為索引去查資料。
// 但如果我們想用「英文名字 (string)」去查他的「分數 (int)」，該怎麼做？
// 答案就是 **Map (關聯式容器 / 鍵值對 Key-Value Pair)**！
//
// 概念：
// - **Key (鍵)**：用來查詢的鑰匙 (例如：學生的名字 "Jasper")，Key 必須是唯一的。
// - **Value (值)**：被查詢的內容 (例如：分數 95)。
//
// C++ 的兩種 Map：
// 1. `std::unordered_map` (哈希表) ➡️ 速度極快 ($O(1)$ 搜尋)，但資料是無序的。
// 2. `std::map` (紅黑樹) ➡️ 速度稍慢 ($O(\log N)$ 搜尋)，但會自動幫你的 Key 進行排序。

int main() {
    std::cout << "=== 1. 基礎 Map 操作 (學生分數查詢) ===" << std::endl;

    // 宣告一個 map：Key 是字串 (姓名)，Value 是整數 (分數)
    std::unordered_map<std::string, int> scoreMap;

    // TODO 1: 插入資料到 scoreMap 中。
    // 提示：直接使用 `scoreMap[Key] = Value;` 的直覺寫法！
    // - 把 "Jasper" 的分數設為 95
    // - 把 "Bob" 的分數設為 80
    // - 把 "Alice" 的分數設為 92
    // [在此寫下代碼]
    scoreMap["Jasper"] = 95;
    scoreMap["Bob"] = 80;
    scoreMap["Alice"] = 92;



    // TODO 2: 查詢並印出特定學生的分數。
    // 提示：直接使用 `scoreMap["姓名"]` 讀取。
    std::cout << "Jasper 的分數是: " << scoreMap["Jasper"] << std::endl;
    std::cout << "Bob 的分數是: " << scoreMap["Bob"] << std::endl;


    // ========================================================
    // 💡 遍歷 Map：使用現代 C++ 17 結構化綁定 (Structured Binding)
    // ========================================================
    // 遍歷 Map 時，每一項都是一個 pair (包含 key 和 value)。
    // 語法：`for (auto const& [name, score] : scoreMap)`
    std::cout << "\n目前 scoreMap 裡的所有資料 (無序):" << std::endl;
    for (auto const& [name, score] : scoreMap) {
        std::cout << "- 姓名: " << name << ", 分數: " << score << std::endl;
    }


    // ========================================================
    // 🎯 實戰應用：單字計數器 (Word Counter)
    // ========================================================
    // 給你一個水果陣列，裡面有重複的水果。請計算每種水果出現了幾次？
    std::cout << "\n=== 2. 實戰應用：水果計數器 ===" << std::endl;

    std::vector<std::string> fruits = {
        "apple", "banana", "apple", "cherry", "banana", "apple", "cherry", "orange"
    };

    // 宣告一個 map，Key 是水果名稱 (string)，Value 是出現次數 (int)
    std::unordered_map<std::string, int> fruitCount;

    // TODO 3: 寫一個 Range-based for 迴圈遍歷 fruits 陣列，累加每種水果的出現次數！
    // 提示：
    // 1. `for (std::string f : fruits)` 遍歷每個水果。
    // 2. 在迴圈中直接寫 `fruitCount[f]++;`。
    //    （C++ 超級聰明！如果該水果第一次出現，它會自動把次數初始化為 0，然後 +1 變成 1！）
    // [在此寫下迴圈代碼]
    for(std::string f : fruits){
        fruitCount[f]++;
    }




    std::cout << "--- 水果計數統計結果 ---" << std::endl;
    // TODO 4: 使用 C++17 結構化綁定 `for (auto const& [fruit, count] : fruitCount)`，
    // 印出每種水果的統計次數 (例如：apple : 3 次)。
    // [在此寫下迴圈代碼]
    for (auto const& [fruit, count] : fruitCount) {
        // 關鍵修正：在結構化綁定中，`fruit` 和 `count` 已經是被拆解出來的變數了！
        // `fruit` 裝著水果名稱，`count` 裝著出現次數。
        // 你不需要再寫 `fruitCount[...]` 去查它，直接把這兩個變數印出來即可！
        std::cout << fruit << " : " << count << " 次" << std::endl;
    }



    return 0;
}

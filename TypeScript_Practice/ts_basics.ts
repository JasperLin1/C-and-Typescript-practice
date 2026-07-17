// ========================================================
// 🎯 TypeScript (TS) 基礎與 C++ 對照指南
// ========================================================
// 恭喜你！你已經征服了 C++。現在我們要將這些觀念無縫平移到 TypeScript！
// TypeScript 是網頁開發 (Web Development) 的霸主。
// 好消息是：你在 C++ 學到的「變數、迴圈、類別 (Class)、泛型 (Generics)」在 TS 中完全通用！
//
// 🌟 最大的差別：
// 1. TS 沒有指標 (沒有 * 和 &)！記憶體會自動回收 (Garbage Collection)。
// 2. C++ 用 `int`, `double`；TS 統一用 `number` 代表所有數字。
// 3. C++ 的模板 `template <typename T>`；在 TS 中稱為「泛型 <T>」。

// ========================================================
// 💡 1. 變數與型態 (Variables & Types)
// ========================================================
// C++:  int age = 20;  double price = 99.9;  std::string name = "Jasper";
// TS:   let 變數名: 型態 = 值;
//       const 常數名: 型態 = 值;

let age: number = 20;
let price: number = 99.9; // 整數和浮點數統一都是 number
let ownerName: string = "Jasper";
let isVip: boolean = true;

// 陣列宣告
// C++: std::vector<int> nums;
// TS:  let nums: number[] = [10, 20, 30];
let scores: number[] = [90, 85, 95];

console.log("=== 1. 變數測試 ===");
console.log(`姓名: ${ownerName}, 年齡: ${age}, 分數: ${scores}`);

// ========================================================
// 💡 2. 函式 (Functions)
// ========================================================
// C++: int add(int a, int b) { return a + b; }
// TS:  function 函數名(參數: 型態): 回傳型態 { ... }

function add(a: number, b: number): number {
    return a + b;
}

console.log("\n=== 2. 函式測試 ===");
console.log("10 + 20 =", add(10, 20));

// ========================================================
// 💡 3. 類別與物件導向 (Classes & OOP)
// ========================================================
// TS 的 Class 概念跟 C++ 完全一樣，也支援 `private` 和 `public`。
// 建構子在 TS 中統一命名為 `constructor`！

class Student {
    private name: string;
    private score: number;

    // 建構子 (Constructor)
    constructor(n: string, s: number) {
        this.name = n;
        this.score = s;
    }

    // Getter
    public getName(): string {
        return this.name;
    }

    public getScore(): number {
        return this.score;
    }

    // Setter (安全檢查)
    public setScore(newScore: number): void {
        if (newScore >= 0 && newScore <= 100) {
            this.score = newScore;
        } else {
            console.log("錯誤：無效的分數！");
        }
    }
}

console.log("\n=== 3. 類別測試 ===");
const s1 = new Student("Jasper", 90); // 用 new 宣告物件，不需要寫 delete！
console.log(`${s1.getName()} 的分數是: ${s1.getScore()}`);
s1.setScore(98);
console.log(`修改後分數是: ${s1.getScore()}`);

// ========================================================
// 💡 4. 泛型 (Generics) ── 就是 C++ 的模板 (Template)！
// ========================================================
// C++: template <typename T> class Box { T content; };
// TS:  class Box<T> { content: T; }
//
// 這裡我們用 TS 重新寫一個萬用 Box！

class Box<T> {
    private content: T;

    constructor(val: T) {
        this.content = val;
    }

    public getContent(): T {
        return this.content;
    }
}

console.log("\n=== 4. 泛型測試 ===");
const stringBox = new Box<string>("一隻黃金獵犬"); // 裝字串的盒子
const numberBox = new Box<number>(999);            // 裝數字的盒子

console.log("字串盒子裝著:", stringBox.getContent());
console.log("數字盒子裝著:", numberBox.getContent());

---
比赛链接: https://codeforces.com/contest/2200
比赛日期: 2026-05-03
比赛时长: 2:15
排名:
分数:
AC题数: "4"
总题目数: "8"
Penalty: "2"
---

## 一、 题目复盘

### A. [题目名称]

**难度**： `372` **状态**： <select>
  <option>✅ AC</option>
  <option>❌ WA</option>
  <option>⏱️ TLE</option>
  <option>💡 未做</option>
  <option>部分分</option>
</select>

**提交次数**： 1　**首次提交**：比赛第 `--` 分钟    **罚时**： `--` 分钟

**题型** : 签到

---

### B. [题目名称]

**难度**： `536`   **状态**： <select>
  <option>✅ AC</option>
  <option>❌ WA</option>
  <option>⏱️ TLE</option>
  <option>💡 未做</option>
  <option>部分分</option>
</select>

**提交次数**： 2　　**首次提交**：比赛第 `--` 分钟    **罚时**： `--` 分钟

**题型** : 签到

**错误记录**：
- 忘开 `cin >> t` 多测

---

### C. [题目名称]

**难度**： `790`  **状态**： <select>
  <option>✅ AC</option>
  <option>❌ WA</option>
  <option>⏱️ TLE</option>
  <option>💡 未做</option>
  <option>部分分</option>
</select>

**提交次数**： 2　　**首次提交**：比赛第 `--` 分钟    **罚时**： `--` 分钟

**题型** : 字符串消除

**核心思路**：  
> 消除相邻相同元素 全消完则为YES，扫描一轮没有可消的则为NO

**实现要点**：
- while循环套for训循环检查， 实际上只需使用栈模拟即可

**错误记录**：
-  变更变量的实际作用但是忘记修改变量类型

**收获 & 优化**：
- 遇到这种 `最近相关性` 问题应该立刻想到栈
---
### D. [题目名称]

**难度**： `1285`   **状态**： <select>
  <option>✅ AC</option>
  <option>❌ WA</option>
  <option>⏱️ TLE</option>
  <option>💡 未做</option>
  <option>部分分</option>
</select>

**提交次数**： 1　　**首次提交**：比赛第 `--` 分钟    **罚时**： `--` 分钟

**题型** : 

**核心思路**：  
> 外部相对顺序不会改变，仅仅选择一个索引位置将内部塞进去
> 内部可以任意循环位移
> 由于是排列，所以元素不会重复


**实现要点**：
1. 在 in_part 中找到最小值 in_min，并**以它为起点循环旋转**（(i + in_min_idx) % size）。
2. 在 out_part 中找到第一个**大于 in_min** 的位置 idx，把旋转后的 in_part **插在这里**。
3. 输出：out[0..idx) + rotated_in + out[idx..end]。

**收获 & 优化**：
- 可以使用 `it - begin()` 代替 `distance()`
---

### 二、 赛后补题

### E. [题目名称]

 难度： `1480`     **状态**：`AC`

**赛后补题思路**：
> 显然如果当其中有一个元素存在一个以上的质因子则Alice直接胜利

**正确解法**：
- 开始判断Bob是否直接胜利
- 判断是否存在两个质因子以上的元素
- 如果没有则都为质数或者为 `a^b` 形式，消去指数，遍历一轮基数判断是否为非严格递增即可

---
## 三、比赛反思

**本次暴露的问题**： 
1. 对于栈的应用还不够到位


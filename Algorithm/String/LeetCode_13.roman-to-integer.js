/*
 * @lc app=leetcode id=13 lang=javascript
 *
 * [13] Roman to Integer
 */

// @lc code=start
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  let romanDic = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };
  let sum = 0;
  for (let i = 0; i < s.length - 1; i++) {
    if (romanDic[s[i]] < romanDic[s[i + 1]]) {
      sum += -romanDic[s[i]];
      continue;
    }
    sum += romanDic[s[i]];
  }
  return sum + romanDic[s[s.length - 1]];
};

//console.log(romanToInt("III"));

// @lc code=end

#!/usr/bin/python3
'''Making change'''

def makeChange(coins, total):
  '''Return: fewest number of coins needed to meet total
      If total is 0 or less, return 0
      If total cannot be met by any number of coins you have, return -1
      coins is a list of the values of the coins in your possession
      The value of a coin will always be an integer greater than 0
  '''
  if total <= 0: return 0
  placeholder = total + 1
  memo = {0: 0}
  for i in range(1, total + 1):
      memo[i] = placeholder
      for coin in coins:
          current = i - coin
          if current < 0:
              continue
          memo[i] = min(memo[current] + 1, memo[i])
  if memo[total] == total + 1:
      return -1
  return memo[total]

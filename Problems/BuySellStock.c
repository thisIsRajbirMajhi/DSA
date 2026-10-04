#include <stdio.h>
#include <stdlib.h>

// Best Time to Buy Sell Stock
// Problem: Buy one day, sell a later day. Maximize profit.
// Given prices[i] = stock price on day i, choose one day to buy and a later day to sell to maximize profit.

// prices = [7, 1, 5, 3, 6, 4]
// Buy at 1
// Sell at 6
// Profit = 6 - 1 = 5

// The crucial constraint is: Buy Day < Sell Day

// Brute Force 
// Try every possible buying day and every later selling day
// Time  = O(n²)
// Space = O(1)

void brute_force(int prices[], int size){
    int maxProfit = 0;
    int buyDay;
    int sellDay;

    for(int i = 0; i < size; i++){
        for(int j = i + 1; j < size; j++){
            int currProfit = prices[j] - prices[i];
            if(currProfit > maxProfit){
                maxProfit = currProfit;
                buyDay = i;
                sellDay = j;
            }
        }
    }
    printf("Maximum Profit: %d\n", maxProfit);
    printf("Buy at %d, sell at %d\n", buyDay, sellDay);
}

// Appraoch 2
// Track the minimum price
// As I move through the array, what is the cheapest price I could have bought at before today?
// Time  = O(n)
// Space = O(1)

void approach_two(int prices[], int size){
    int minPrice = prices[0];
    int maxProfit = 0;
    for(int i = 0; i < size; i++){
        int profit = prices[i] - minPrice;
        if(profit > maxProfit){
            maxProfit = profit;
        }
        if(prices[i] < minPrice){
            minPrice = prices[i];
        }
    }
    printf("Maximum Profit: %d\n", maxProfit);
}

// Approach 2
// Maintaining two pointers
void approach_three(int prices[], int size){
    int buy = 0;
    int maxProfit = 0;
    for(int sell = 1; sell < size; sell++){
        if(prices[sell] < prices[buy]){
            buy = sell;
        }
        else {
            int profit = prices[sell] - prices[buy];
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
    }
    printf("Maximum Profit: %d\n", maxProfit);
}

// Approach Four: Kadane's Algorithm
void approach_four(int prices[], int size){
    int current = 0;
    int best = 0;
    for(int i = 1; i < size; i++){
        int change = prices[i] - prices[i - 1];
        current += change;
        if(current < 0){
            current = 0;
        }
        if(current > best){
            best = current;
        }
    }
    printf("Maximum Profit: %d\n", best);
}

int main() {

    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]);
    brute_force(prices, size);
    approach_two(prices, size);
    approach_three(prices, size);
    approach_four(prices, size);
    return 0;
}

// | Approach | Time | Extra Space | Main idea |

// | Brute force                | `O(n²)`| `O(1)` | Try every buy/sell pair 
// | Two-pointer style          | `O(n)` | `O(1)` | Maintain cheapest buy point 
// | Minimum-so-far             | `O(n)` | `O(1)` | Best/simple solution 
// | Kadane                     | `O(n)` | `O(1)` | Convert prices to differences 

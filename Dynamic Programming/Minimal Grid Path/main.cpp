#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
 
using namespace std;
 
// Function to solve the Minimal Grid Path problem using character-by-character greedy DP.
void solve() {
    int N;
    // Fast reading of the grid size
    if (!(cin >> N)) return;
 
    // Read the N x N grid of characters
    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }
 
    // Edge case: N=1 (grid is just one cell)
    if (N == 1) {
        cout << grid[0][0] << "\n";
        return;
    }
 
    // --- Dynamic Programming State ---
    // 'current_positions' stores all coordinates (row, col) that are endpoints 
    // of the lexicographically minimal path prefixes found up to the current step.
    // It starts at the top-left cell.
    vector<pair<int, int>> current_positions{{0, 0}};
 
    // The result string starts with the character at the upper-left corner.
    string minimal_path = "";
    minimal_path += grid[0][0];
 
    // The total path length is 2*N - 1. We have the first character, so we need 2*N - 2 more steps.
    const int steps_needed = 2 * N - 2;
 
    for (int k = 0; k < steps_needed; ++k) {
        // Step 1: Find the lexicographically smallest character (min_char) 
        // that is reachable from the current set of optimal positions.
        char min_char = 'Z' + 1; // Initialize with a character larger than 'Z'
 
        // Step 2: Determine candidates and the minimal character simultaneously.
        // We use a vector to store all reachable candidate positions.
        vector<pair<int, int>> next_candidates;
        
        for (const auto& p : current_positions) {
            int r = p.first;
            int c = p.second;
            
            // Try moving DOWN (r+1, c)
            if (r + 1 < N) {
                // Update the minimum character found so far
                min_char = min(min_char, grid[r + 1][c]);
                // Add the position to the candidate list
                next_candidates.push_back({r + 1, c});
            }
            
            // Try moving RIGHT (r, c+1)
            if (c + 1 < N) {
                // Update the minimum character found so far
                min_char = min(min_char, grid[r][c + 1]);
                // Add the position to the candidate list
                next_candidates.push_back({r, c + 1});
            }
        }
        
        // Append the minimal character found to the result path
        minimal_path += min_char;
 
        // Step 3: Pruning and updating the optimal state (P_k -> P_{k+1}).
        // Only keep candidate positions that contain the minimal character (min_char).
        vector<pair<int, int>> next_optimal_positions;
 
        for (const auto& p : next_candidates) {
            if (grid[p.first][p.second] == min_char) {
                next_optimal_positions.push_back(p);
            }
        }
        
        // To maintain O(N) size for 'current_positions', remove duplicate coordinates.
        // Sort and then use std::unique.
        sort(next_optimal_positions.begin(), next_optimal_positions.end());
        next_optimal_positions.erase(
            unique(next_optimal_positions.begin(), next_optimal_positions.end()), 
            next_optimal_positions.end()
        );
        
        // Update the state for the next iteration
        current_positions = next_optimal_positions;
    }
 
    // Output the final minimal path
    cout << minimal_path << "\n";
}
 
int main() {
    // Optimization for faster input/output operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    solve();
 
    return 0;
}

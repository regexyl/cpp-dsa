---
description: Slightly more advanced use of C++ in LC answers
---

# Advanced C++ in LC

### Find Players With Zero or One Losses
Beats 99.19% in runtime and 99.99% in memory.
```cpp
class Solution {
public:
    std::vector<std::vector<int>> findWinners(
        const std::vector<std::vector<int>> &matches
    ) {
        static constexpr size_t N = 1e5;

        static int losses[N + 1];
        std::memset(losses, -1, sizeof(losses));

        for (const auto &m : matches) { // const auto &
            if (auto &winnerLosses = losses[m[0]]; winnerLosses == -1)
                winnerLosses = 0;

            if (auto &loserLosses = losses[m[1]]; loserLosses == -1)
                loserLosses = 1;
            else
                ++loserLosses;
        }

        std::vector<std::vector<int>> out;
        for (const auto target : { 0, 1 }) {
            size_t count = 0;
            for (size_t player = 1; player <= N; ++player)
                count += losses[player] == target;
            
            std::vector<int> outLine;
            outLine.reserve(count);

            for (size_t player = 1; player <= N; ++player)
                if (losses[player] == target)
                    outLine.emplace_back(player);

            out.emplace_back(std::move(outLine));
        }

        return out;
    }
};
`
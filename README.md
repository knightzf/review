review
======
How to enumerate all combinations of letters when given a vector of strings?
A: Use recursion and an index to keep track of which element in the vector are we at and use copy to concatenate temporary result.

void getCombinations(const std::vector<std::string>& rows,
                         int idx,
                         std::string nextRow,
                         std::vector<std::string>& combinations)
{
    if(idx >= rows.size())
    {
        combinations.push_back(nextRow);
        return;
    }

    for(int i = 0; i < rows[idx].size(); ++i)
    {
        getCombinations(rows, idx + 1, nextRow + rows[idx][i], combinations);
    }
}


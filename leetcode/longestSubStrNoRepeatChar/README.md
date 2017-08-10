1. Simple solution uses multiple maps to store unique consective characterss, when there's a duplicate, go back to the index after the duplicate and keep going. It works but slow as there are more maps being used.

2. Better solution uses only one set and use another index to point the start of valid substring. Use current loop index and start of valid substring to calculate substring length. There is a little trickiness in the logic but the idea is not complex.

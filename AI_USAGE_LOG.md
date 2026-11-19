# AI Usage Log

This file documents how AI tools were used while building this project.

---

| AI Tool | Prompt / Question Asked | How I Used and Verified It |
|---|---|---|
| ChatGPT | "Suggest 4 simple categories of academic advice based on CGPA on a 10-point scale, with example messages for each. Keep it beginner-friendly." | Got suggestions for 4 categories: Excellent, Good, Needs Improvement, Requires Immediate Attention. I decided the CGPA thresholds myself (8.5, 7.0, 5.5) based on how our grading works. Wrote the if-else logic in C on my own. |
| ChatGPT | "What is the difference between fgets and scanf for reading strings with spaces in C?" | Used this to understand why I needed fgets for the student name field (names can have spaces). Tested it in my program with a name like "Ansh Sharma" to confirm it works. |
| ChatGPT | "Give me 3-4 test cases to verify a CGPA calculation function that averages only non-zero values." | Used the suggested cases manually with my 5 test students. Found that one edge case (all zeros) returned 0, which I verified was handled correctly by my if(done == 0) check. |

---

## Note

AI was used only to understand concepts and get ideas. All code was written by me and I can explain every line of it.

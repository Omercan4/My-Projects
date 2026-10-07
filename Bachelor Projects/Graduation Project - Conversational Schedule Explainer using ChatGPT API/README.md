**Graduation Project - Conversational Schedule Explainer using ChatGPT API**

This paper is a final report on the project "Conversational Schedule Explainer with
ChatGPT." It addresses the challenge of transparency and understanding in employee
scheduling in the service industry due to the continuous and fluctuating nature of demand.
The project integrates advanced optimization models with a user-friendly interface, utilizing
Gurobi for optimization and ChatGPT API for natural language processing. This system aims
to provide clear explanations for scheduling decisions, improving employee engagement and
operational efficiency. The report also delves into the underlying functions of the system,
exploring how it answers complex scheduling queries and facilitates user interactions through
an intuitive interface. It emphasizes the importance of this ergonomic design for a better user
experience in workforce management.

**How it works:** Gurobi optimization models create the employee schedules. A Streamlit chat interface takes questions in
natural language, and OpenAI function calling (`gpt-3.5-turbo-0613`) maps each question to one of the Python tools
(`get_shift_schedule`, `find_employees_on_same_shift`, `find_employees_with_same_skillset`, `find_possible_swaps`,
`check_shift_compatibility`, `reschedule_shift`). The tool result is then explained back to the user in plain language.
This is agent-style LLM tool use from 2023/24, shortly after OpenAI introduced function calling (June 2023).

Contributors: Murat Tutar, Bora Polater

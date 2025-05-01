
# Enhancing Source-to-Source Code Translation with Genetic Improvement Techniques

This project provides tooling for source-to-source transpilation repair using LLMs and Genetic Improvement techniques.

## 🐍 Requirements

- **Python**: 3.11 or newer  
- **Virtual Environment (recommended)**

Set up a virtual environment in the project root:

```bash
python -m venv .venv
source .venv/bin/activate  # On Windows use `.venv\Scripts\activate`
```

## 📦 Installation

Install the required dependencies:

```bash
pip install -r requirements.txt
```

## 🔐 API Keys

You will need **two API keys**:

1. **OpenAI API Key**  
2. **Groq API Key**

### Setup

- Create a `.env` file in the `magpie_llm-745B/` directory with the following:

```
OPENAI_API_KEY=<your_openai_key>
```

- Set your Groq API key as an environment variable in your shell:

```bash
export GROQ_API_KEY=<your_groq_key>
```

> On Windows, use `set GROQ_API_KEY=<your_groq_key>` instead.

---

## 🧪 Run LLM Preprocessor

To perform a single run of the LLM Preprocessor stage:

```bash
python experiments_pipeline.py --mode test --run_number 1 --files test
```

To run on the training data, modify:

```bash
python experiments_pipeline.py --mode train --run_number 1 --files train
```

---

## 🧬 Run Genetic Improvement Pipelines

We support three types of GI pipelines: `standard`, `llm-crossover`, and `novel-mutation`.

Example runs on the **test set**:

```bash
python gi_pipeline.py --run_number 1 --mode standard --set test
python gi_pipeline.py --run_number 1 --mode llm-crossover --set test
python gi_pipeline.py --run_number 1 --mode novel-mutation --set test
```

To run on the **EvalPlus train set**:

```bash
python gi_pipeline.py --run_number 1 --mode <pipeline_mode> --set train
```

Replace `<pipeline_mode>` with `standard`, `llm-crossover`, or `novel-mutation`.

---

## 📁 Project Structure

```bash
.
├── dataset/                  # Original EvalPlus dataset
├── LLM-Translations/         # Output from LLM-based translation
├── magpie_llm-745B/          # Modified MAGPIE tool containing LLM Preprocessor & Rule-based Test Generation
│   ├── llm_preprocessor.py   # Script for fixing syntax errors and semantic issues
│   ├── create_tests.py       # Rule-based test generation script
│   └── .env                  # Environment configuration file
├── rule-based-translations/  # Output from rule-based translation
├── .gitignore                # Files/directories to ignore in Git
├── README.md                 # Project overview and instructions
└── requirements.txt          # Python dependencies
```

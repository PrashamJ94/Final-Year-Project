for i in {1..5}
do
    echo "Running GI experiment with run number $i"
    python gi_pipeline.py --run_number $i --mode standard --set test
done

for i in {1..5}
do
    echo "Running GI experiment with run number $i"
    python gi_pipeline.py --run_number $i --mode llm-crossover --set test
done

for i in {1..5}
do
    echo "Running GI experiment with run number $i"
    python gi_pipeline.py --run_number $i --mode novel-mutation --set test
done
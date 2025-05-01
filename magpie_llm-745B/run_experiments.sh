for i in {1..5}
do
    echo "Running experiment with run number $i"
    python experiments_pipeline.py --mode test --run_number $i --files test
done
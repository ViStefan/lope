

echo testing bash
bash -c ". ./lope; export LOPE_FILE=/lope_test/test/.lopefile; echo \$LOPE_FILE; lope dir; pwd; lope 1; pwd; lope A; pwd; lope dv; pwd"

echo

echo testing zsh
zsh -c ". ./lope; export LOPE_FILE=/lope_test/test/.lopefile; echo \$LOPE_FILE; lope dir; pwd; lope 1; pwd; lope A; pwd; lope dv; pwd"

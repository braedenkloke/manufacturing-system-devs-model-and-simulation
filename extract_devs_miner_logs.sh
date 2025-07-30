# !/bin/sh
#
# Extracts an event and state log from a given simulation log.
# Output is formatted as per the DEVS-miner process mining algorithm input requirements.

SIMULATION_LOG='output_data/raw/manufacturing_sys_log.csv'
NUM_SYS_MODELS=3

# Extract event log
awk -F, '/eventLog/ { print $1 "," $6 "," $8 "," $9}' $SIMULATION_LOG > 'output_data/cleaned/manufacturing_sys_event_log.csv'

# Extract state log
#
# Simulator appends final states of model to logs.
# This data is removed since each model's final state is recorded earlier in the log.
head -n -$NUM_SYS_MODELS $SIMULATION_LOG | awk -F, '/stateLog/ { print $1 "," $3 "," $6}' > 'output_data/cleaned/manufacturing_sys_state_log.csv'


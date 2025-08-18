# !/bin/sh
#
# Extracts an event and state log from a given simulation log.
# Output is formatted as per the DEVS-miner process mining algorithm input requirements.

SIMULATION_LOG='output_data/raw/manufacturing_system_log.csv'
NUM_SYS_MODELS=3

# Extract event log
awk -F, 'BEGIN { print "timestamp,order_id,resource,event" } /eventLog/ { print $1 "," $6 "," $8 "," $9}' $SIMULATION_LOG \
    > 'output_data/cleaned/manufacturing_system_event_log.csv'

# Extract state log
#
# Simulator appends final states of model to logs.
# This data is removed since each model's final state is recorded earlier in the log.
head -n -$NUM_SYS_MODELS $SIMULATION_LOG | awk -F, \
    'BEGIN { print "timestamp,resource,state" } /stateLog/ { print $1 "," $3 "," $6}' \
    > 'output_data/cleaned/manufacturing_system_state_log.csv'


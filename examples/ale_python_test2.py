#!/usr/bin/env python

# ale_python_test1.py
# Author: Ben Goodrich
#
# This modified ale_python_test1.py to do more extensive tests of the python interface
# by calling more functions
import sys
from ale_python_interface import ALEInterface
import numpy as np

if(len(sys.argv) < 2):
    print("Usage ./ale_python_test2.py <ROM_FILE_NAME>")
    sys.exit()

ale = ALEInterface()

max_frames_per_episode = ale.getInt("max_num_frames_per_episode");
ale.set("random_seed",123)

random_seed = ale.getInt("random_seed")
print("random_seed: " + str(random_seed))

ale.loadROM(sys.argv[1])
legal_actions = ale.getMinimalActionSet()

for episode in range(10):
    total_reward = 0.0 
    while not ale.game_over():
        a = legal_actions[np.random.randint(legal_actions.size)]
        reward = ale.act(a);
        total_reward += reward
    episode_frame_number = ale.getEpisodeFrameNumber()
    frame_number = ale.getFrameNumber()
    print("Frame Number: " + str(frame_number) + " Episode Frame Number: " + str(episode_frame_number))
    print("Episode " + str(episode) + " ended with score: " + str(total_reward))
    ale.reset_game()


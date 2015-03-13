#!/usr/bin/env python

# ale_python_test_pygame.py
# Author: Ben Goodrich
#
# This modified ale_python_test1.py to display screen contents using pygame
import sys
from ale_python_interface import ALEInterface
import numpy as np
import pygame

if(len(sys.argv) < 2):
    print("Usage ./ale_python_test_pygame.py <ROM_FILE_NAME>")
    sys.exit()

ale = ALEInterface()

max_frames_per_episode = ale.getInt("max_num_frames_per_episode");
ale.set("random_seed",123)

random_seed = ale.getInt("random_seed")
print("random_seed: " + str(random_seed))

ale.loadROM(sys.argv[1])
legal_actions = ale.getMinimalActionSet()

(screen_width,screen_height) = ale.getScreenDims()
print("width/height: " +str(screen_width) + "/" + str(screen_height))

#init pygame
pygame.init()
screen = pygame.display.set_mode((screen_width,screen_height))
pygame.display.set_caption("Arcade Learning Environment Random Agent Display")

pygame.display.flip()

episode = 0
total_reward = 0.0 
while(episode < 10):
    exit=False
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit=True
            break;
    if(exit):
        break

    a = legal_actions[np.random.randint(legal_actions.size)]
    reward = ale.act(a);
    total_reward += reward

    numpy_surface = np.frombuffer(screen.get_buffer(),dtype=np.int32)
    ale.getScreenRGB(numpy_surface)
    pygame.display.flip()
    if(ale.game_over()):
        episode_frame_number = ale.getEpisodeFrameNumber()
        frame_number = ale.getFrameNumber()
        print("Frame Number: " + str(frame_number) + " Episode Frame Number: " + str(episode_frame_number))
        print("Episode " + str(episode) + " ended with score: " + str(total_reward))
        ale.reset_game()
        total_reward = 0.0 
        episode = episode + 1


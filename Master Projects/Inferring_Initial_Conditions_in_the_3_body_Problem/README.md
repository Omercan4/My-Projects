
# Inferring Initial Conditions in the Three Body Problem

**Project Aim:** The project aims to infer the initial positions and velocities of a three-body gravitational system based on observations of its trajectories at a later time. Because these systems are chaotic and sensitive to minute changes in initial conditions, Simulation-Based Inference (SBI) to map observed trajectories to a posterior distribution of the starting parameters was utilized.

**Definition:** The three-body problem is a classic physics challenge involving the prediction of the motion of three point masses under their mutual gravitational attraction; while general analytical solutions do not exist, numerical methods can approximate their complex and often chaotic movements

**Summary:** Using the BayesFlow framework, the team simulated synthetic trajectory data with a high-accuracy Runge-Kutta (RK4) solver and added 1% Gaussian noise to mimic observational uncertainty. After testing various neural architectures, they found that a Coupling Flow inference network paired with an LSTM summary network provided the most robust results for estimating initial conditions across different snapshot lengths. While velocity parameters proved more difficult to recover than positions, the model successfully demonstrated that deep learning can bypass the need for analytical solutions in complex, intractable simulations

Additional Contributors: Yordan Saputra, Tobias Rumpe

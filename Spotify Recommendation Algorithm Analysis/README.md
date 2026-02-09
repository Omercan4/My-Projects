
# Spotify Recommendation Algorithm Analysis

### Project Aim
The primary objective of this study is to analyze the sensitivity of Spotify’s recommendation engine to content-based seeds and user-specific metadata. By utilizing a full factorial experimental design simulating 90 unique user profiles, the study measures the association between a minimal two-song "cold-start" seed and the resulting 50 recommended tracks. This research seeks to move beyond viewing algorithmic curation as a "black box" by quantifying how the system extrapolates long-term preferences from immediate session inputs. By mapping audio properties into a high-dimensional vector space, the project evaluates whether the platform prioritizes the inherent acoustic features of the seeds or integrates demographic data to customize the listener's experience.

### Definition
To evaluate the underlying mechanisms of Spotify’s personalization-diversity trade-off, this report addresses three central research questions within a unified statistical framework:

1. **Impact of Initial Playlist:** To what extent do the genre and specific audio features (e.g., danceability, energy, acousticness) of the seed playlist dictate the characteristics and genre of the recommended tracks?
2. **Influence of User Demographics:** Do demographic factors—specifically gender and age (represented by three distinct generational cohorts)—exert a statistically significant influence on recommendations, or does the algorithm remain demographic-agnostic in its response to seed songs?
3. **Acoustic Distance and Similarity:** Utilizing Cosine Similarity and inferential statistics (One-Way ANOVA and t-tests), which mathematical framework best quantifies the acoustic distance between the user-provided input and the algorithm’s output across different musical genres?

### Additional Contributors

* **Yordan Saputra**
* **Jiahui Fan**

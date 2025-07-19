# Contributing

### Branch names

 `main` - upstream branch

 naming scheme for new branches use:
  - `docs_*` - for docs
  - `feature_*` - for features
  - `fix_*` - for fixes

 Note: replace `*` with general word that describe main part of PR
 
### Commits text format

 Make is simple and short.  
 For example:
 ```
 feat: short description  
 fix: bug description  
 refactor: internal change
 ```

See [here](https://gist.github.com/joshbuchea/6f47e86d2510bce28f8e7f42ae84c716) for more details

### How to submit PR?

 1. Make new branch from `main` 
 2. Make your changes into new branch
 3. Push branch with your changes
 4. Open Pull Request (PR)
 5. Wait for review  
  If review is approved - close PR, and delete your branch  
  Else edit what's needed and move to step 5

### Review Process
 Every PR must be reviewed by at least one team member before merging.  
 Reviewers should:
  - Check for code clarity and readability
  - Ensure adherence to project architecture and style guidelines
  - Verify that the code compiles and runs properly
  - Check for regressions or broken functionality
  - Leave constructive feedback or request changes if needed

 Merge Requirements
  - At least 1 approval from a team member is required
  - No self-merging — you may not approve and merge your own PR
  - The PR must have no unresolved review comments
  - The PR must not break the main branch (keep builds green)

 Optional but Recommended
  - Link relevant issues in the PR description: `Closes #12, Fixes #7`
  - Mark PRs as Draft if they're not ready for review
  - Use descriptive PR titles:
    ``` 
    ✅ Implement resource generation system
    ❌ stuff for map
    ```

### Code formatting

To keep our code clean and consistent, we use clang-format based on the Google C++ Style Guide, with a few small changes.
Basic Rules:

 - 4 spaces for indentation (no tabs)
 - Braces on the same line (if (...) {)
 - Maximum line length: 100 characters
 - Pointer and reference symbols aligned with the type (int* ptr, const string& name)
 - Short functions and if statements can be written in one line if they are simple

Naming:

 - Змінні та функції — camelCase:


    int totalCount;
    void renderScene();

 - Класи та структури — PascalCase:


    class GameEngine { ... };

 - Константи — kCamelCase:

   
    const int kMaxPlayers = 4;

 - Namespace — lower_case_with_underscores:

    
    namespace game_utils { ... }

How to format your code:

 Use clang-format before submitting a PR:
    
    clang-format -i your_file.cpp

Or format all .cpp and .h files:

    find . -regex '.*\.\(cpp\|h\)' -exec clang-format -i {} +

Make sure your IDE (e.g., VSCode or CLion) uses the .clang-format file in the project root.

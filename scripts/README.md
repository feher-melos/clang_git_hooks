# Installation

Edit `.git/hooks/pre-push` and add the following line to the top:

```
./scripts/git-hooks/pre-push "$@" || exit 1
```

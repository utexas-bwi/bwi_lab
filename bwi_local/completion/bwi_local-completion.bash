_bwi()
{
    local cur prev cmds
    COMPREPLY=()
    cur="${COMP_WORDS[COMP_CWORD]}"
    prev="${COMP_WORDS[COMP_CWORD-1]}"
    cmds="$(ls /usr/local/lib/bwi_local)"

    if [[ ${prev} == "bwi" ]] ; then
        COMPREPLY=($(compgen -W "${cmds}" -- "${cur}"))
        return 0
    fi
}
complete -F _bwi bwi

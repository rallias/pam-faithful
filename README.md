# pam-faithful

An interface to PAM for Node.JS

## Usage:

* pam_handle = pam_faithful.pam_start(service_name, user, conv)

    Adaptation of [pam_start(3)](https://www.freebsd.org/cgi/man.cgi?query=pam_start&sektion=3) to NodeJS.

    The pam_start() function creates and initializes a PAM context.

    * The `service` argument specifies the name of the policy to apply.

    * The `user` argument specifies the name of the target user - the user the created context will serve to authenticate.

    * The `conv` argument is an application-defined callback to communicate with the user, in the following form:

        Promise<string|string[]>|string|string[] conv({msg_style, msg}[])

        * `msg_style` is one of four types:

            * `pam_faithful.PAM_PROMPT_ECHO_OFF`: Display a prompt and accept the user's resposne without exposing it on the input interface. This is commonly used for passwords.

            * `pam_faithful.PAM_PROMPT_ECHO_ON`: Display a prompt and accept the user's response, exposing it on the input interface. This is commonly used for login names and one-time passphrases.

            * `pam_faithful.PAM_ERROR_MSG`: Display an error message.

            * `pam_faithful.PAM_TEXT_INFO`: Display an informational message.

        * `msg`: The message to display.

        On success, the conv function should return an array of strings with the same number of responses as there were input messages. In the event one message was submitted, a regular string is acceptable. The conv function may also return a promise in the event it needs to perform additional processing in order to obtain the response.

        pam_faithful will interpret an unmatched number of responses or a promise error as a failure, and respond appropriately.

    The pam_start() function returns one of the following values:

    * `pam_faithful.PAM_SUCCESS`: Success.

    * `pam_faithful.PAM_BAD_ITEM`: Unrecognized or restricted item.

    * `pam_faithful.PAM_BUF_ERR`: Memory buffer error.

    * `pam_faithful.PAM_SYSTEM_ERR`: System error.
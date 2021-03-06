/*
    Copyright © 2012 Syd Logan. All Rights Reserved.

    Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.

    3. The name of the author may not be used to endorse or promote products
derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY Syd Logan "AS IS" AND ANY EXPRESS OR IMPLIED
WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#include "context.h" 

/** 
 * push an array or object onto the stack, setting its parent to
 * the current top of stack, in any.
 *
 * @param[in] obj object to push
 * 
 * @return true always
 */

bool
Context::Push(JsonNode *obj)
{
    if (!m_stack.empty()) {
        obj->SetParent(Current());
    }
    m_stack.push_front(obj);
    return true;
}


/**
 * Remove the top element from the context stack.
 *
 * @return object that was on the stack, or NULL if none.
 */

JsonNode *
Context::Pop()
{
    JsonNode *obj = NULL;

    if (!m_stack.empty()) {
        obj = m_stack.front();
        m_stack.pop_front();
    }
    return obj;
}


/**
 * Return the current top of stack object.
 *
 * @return the current top of stack object, or NULL.
 */

JsonNode *
Context::Current()
{
    JsonNode *ret = NULL;

    if (!m_stack.empty()) {
        ret = m_stack.front();
    }
    return ret;
}


package de.uni_kassel.vs.cn.ttb_apps.marauders_map.command;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by marci on 01.03.16.
 */
public final class GlobalCommandList {
    public static final List<Command> COMMANDS = new ArrayList<Command>();

    public static final Command getCommandOfType(Class theClass) {
        for (Command command : COMMANDS) {
            if(command.getClass().equals(theClass)) {
                return command;
            }
        }

        return null;
    }
}

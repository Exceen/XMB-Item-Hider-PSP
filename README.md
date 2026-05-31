# XMB Item Hider PSP

XMB Item Hider (aka XrossMediaBar™ Item Hider) plugin for PSP. Upgraded to include option to _completely_ hide XMB categories (not just the menu items _within_ categories). The biggest appeal is the ability to hide the largely unused **Network** and **PlayStation®Network** (PSN) categories.

Continuation of Frostegater's project: https://www.gamebrew.org/wiki/XMB_Item_Hider_PSP

Tested on:
- 6.61 ARK-4
- 6.61 ARK-5

#### <ins>Installation:</ins>
1\. Download & Extract the `.zip` from [the latest Release](https://github.com/wad11656/XMB-Item-Hider-PSP/releases/latest)<br>

2\. Move the included `.prx` and `.ini` to `<MemoryStick>:/SEPLUGINS` _(non-PSP Go)_ or `<InternalStorage>:/SEPLUGINS` _(PSP Go)_.<br>

&nbsp;&nbsp;&nbsp;&nbsp;3a\. **ARK CFW:** Add `vsh, ms0:/SEPLUGINS/xmbih.prx, on` _(non-PSP Go)_ or `vsh, ef0:/SEPLUGINS/xmbih.prx, on` _(PSP Go)_ to your `<StorageDevice>:/SEPLUGINS/PLUGINS.txt`.<br>

&nbsp;&nbsp;&nbsp;&nbsp;3b\. **Non-ARK CFW:** Add `ms0:/SEPLUGINS/xmbih.prx 1` _(non-PSP Go)_ or `ef0:/SEPLUGINS/xmbih.prx 1` _(PSP Go)_ to your `<StorageDevice>:/SEPLUGINS/VSH.txt`.<br>

4\. Open the `.ini` file in a text editor and hide icons by entering a `1` value, and completely hide Global XMB categories with a `2` value.<br>

5\. Boot your PSP/Reset the VSH (XMB).

#### <ins>Start on Memory Stick:</ins>
Set `START_AT_MEMORY_STICK = 1` under `[Global]` in the `.ini` to make the XMB boot with the cursor on **Memory Stick** in the `Game` category instead of `Saved Data Utility` / `Game Sharing`.

It briefly hides those items (and the UMD disc, if inserted) during boot so the cursor settles on Memory Stick, then re-adds them automatically once the XMB has finished loading — so everything stays accessible. The re-add is tied to a detected "XMB ready" signal (no fixed delay).

#### <ins>Move Extras items (ARK only):</ins>
Set `MOVE_EXTRAS_ITEMS = 1` under `[Global]` in the `.ini` to relocate ARK's CFW menu items out of the `Extras` category and then hide `Extras`:
- **Custom Launcher** → top of the `Game` category (before `Game Sharing`)
- **CFW Settings** + **Plugins Manager** → end of the `Settings` category

The items are captured as ARK injects them during boot and re-added to their new homes once the XMB has finished loading (same "XMB ready" signal as above), so they keep working — selecting them is unaffected. The cursor still starts on `Memory Stick` when combined with `START_AT_MEMORY_STICK`. Because the items inherit ARK's PlayStation®Network icon keys (which don't render outside that column), the relocated `Settings` items are given stock `Settings` icons (System gear / Theme).

> **Using [Game Categories Lite](https://github.com/Exceen/game-categories-lite)?** Hiding `Extras` shifts the `Game` column's index, which Game Categories Lite must account for or it stops finding `Game`. Use a build of Game Categories Lite that recognizes `MOVE_EXTRAS_ITEMS=1` in `xmbih.ini` (it reads the shift from there). Deploy both plugins together.

#### <ins>Known Limitations:</ins>
- You can't completely hide the leftmost `Settings` category with `HIDE_ALL_SETTINGS = 2` in the `.ini` file--only its contents (`HIDE_ALL_SETTINGS = 1`). (The `Settings` category seems to act as the "anchor" for the rest of the categories.)
  - `Settings` *does* get hidden with `HIDE_ALL = 2`.
- Completely hiding any category to the left of the `Game` category can cause buggy behavior with `Game` menu items. (i.e., Duplicated `Memory Stick` entries; Deleted `Resume Game` entries don't properly disappear until the next full VSH reset.)

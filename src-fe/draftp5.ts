
const miroProject = {
  id: "ssc01",
  info: {
    uid: "AC56-CB32-7600-BFF9",
    createTs: 12345009,
    updateTs: 12345009,
  },

  assets: {
    colors: {
      base: ["#DEF673", "#730034"],
    }
  },

  gradients: [
    {
      id: "gr01",
      type: "linear",
      colors: [[0.2, "@base:3"], [0.5, "@base:3/l-=0.2"], [1,"@base:3/l+=0.2"]],
    },
  ],

  stacks: [
    {
      uid: "AC56-CB32-7600-BFF9",
      crc: 0x8708A3D2,
      background: "transparent",  // or transparent
      layers: [
        {
          uid: "AC56-CB32-7600-BFF9",
          crc: 0x8708A3D2,
          id: "S01L001",
          type: "BASIC_SHAPE",
          subtype: "rect",
          center: [200, 100],
          bbox: [80, 60],  // w, h
          radius: 4,  // or [4, 3], or [4, 3, 0, 2]
          rotation: -30,
          data: {
            coords: [],  // relative to center.
          },
        },
        {
          uid: "23DF-0032-EE78-BFF9",
          crc: 0x8708A3D2,
          id: "S01L002",
          type: "BASIC_SHAPE",
          subtype: "polygon",
          center: [200, 100],
          bbox: [80, 60],  // w, h
          radius: 4,  // or [4, 3], or [4, 3, 0, 2]
          rotation: 0,
          transform: "tr:-34,90",  // or rot(0rad) | flip:0,1 | mat(0,0,0,0,0,0)
          data: {
            coords: [],  // relative to center.
          },
        },
      ],  // layers.
    },

    {
      uid: "5410-CB32-7600-BFF9",
      crc: 0x8708A3D2,
      background: "@base:3",  // lowest layer cant be transparent
      // No layers.
    },
  ],  // stacks.

  fills: [
    {
      id: "AC56-CB32-7600-BFF9",
      type: "STROKE_AND_FILL",
      // Possible values:
      // @null
      // @asset:0 / base:0
      // @stack:A23D
      // #FF00FF
      // -- Can modify : alpha, lightness
      // #FF00FF/a=0.3, @stack:A23D/l=0.1, @stack:A23D/l+=0.1
      colors: ["@base:2", "@null"],
    },
    {
      id: "23DF-0032-EE78-BFF9",
      type: "STROKE_AND_FILL",
      colors: ["@null", "@stack:20"],
    },
  ],
};

export default miroProject;